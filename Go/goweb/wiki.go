/**
https://golang.org/doc/articles/wiki/
Go webapp demo
Makhtar Diouf
*/
package main

import (
	"errors"
	"fmt"
	"html/template"
	"io"
	"io/ioutil"
	"log"
	"net/http"
	"regexp"
)

// Page Content
type Page struct {
	Title string
	Body  []byte
}

var validPath = regexp.MustCompile("^/(edit|save|view)/([a-zA-Z0-9]+)$")

func main() {
	port := 9000
	fmt.Printf("Access the app from http://localhost:%d\n", port)
	runWebServer(port)
}

func runWebServer(port int) {

	http.HandleFunc("/view/", viewAction)
	http.HandleFunc("/edit/", editAction)
	http.HandleFunc("/save/", saveAction)
	http.HandleFunc("/", indexAction)
	log.Fatal(http.ListenAndServe(fmt.Sprintf(":%v", port), nil)) // ":9000"
}

// Persist page data to a file
func (p *Page) save() error {
	filename := "data/" + p.Title + ".txt"
	err := ioutil.WriteFile(filename, p.Body, 0600)
	if err != nil {
		log.Println("Could not save ", filename, err)
	}
	return err
}

func loadPage(title string) (*Page, error) {
	filename := "data/" + title + ".txt"
	body, err := ioutil.ReadFile(filename)
	if err != nil {
		return nil, err
	}
	return &Page{Title: title, Body: body}, nil
}

func getTitle(w http.ResponseWriter, r *http.Request) (string, error) {
	m := validPath.FindStringSubmatch(r.URL.Path)
	if m == nil {
		http.NotFound(w, r)
		return "", errors.New("Invalid Page Title")
	}
	return m[2], nil // The title is the second subexpression.
}

func renderTemplate(w http.ResponseWriter, tmpl string, p *Page) {
	t, err := template.ParseFiles("views/" + tmpl + ".html")
	t.Execute(w, p)
	if err != nil {
		http.Error(w, err.Error(), http.StatusInternalServerError)
		return
	}
}

func indexAction(w http.ResponseWriter, r *http.Request) {
	//title := r.URL.Path[len("/"):]
	filesInfo, err := ioutil.ReadDir("./data/")
	_ = filesInfo
	if err != nil {
		msg := fmt.Sprintf("Cannot access data files", err)
		io.WriteString(w, msg)
		log.Printf(msg)
		//http.Redirect(w, r, "/edit/"+title, http.StatusFound)
		return
	}

	t, err := template.ParseFiles("index.html")
	body := ""
	// List existing pages names, no the best way 
	for _, f := range filesInfo {
		//io.WriteString(w, f.Name() + "<br>")
		body += f.Name() + "\n"
	}
	p := Page{Body: []byte(body)}
	t.Execute(w, p) 
	
}

func viewAction(w http.ResponseWriter, r *http.Request) {
	title, err := getTitle(w, r)
	if err != nil {
		msg := fmt.Sprintf("Invalid title string %v", title, err)
		io.WriteString(w, msg)
		log.Printf(msg)
		return
	}
	p, err := loadPage(title)
	if err != nil {
		msg := fmt.Sprintf("Page '%s' doesn't exist: %v", title, err)
		io.WriteString(w, msg)
		log.Printf(msg)
		//http.Redirect(w, r, "/edit/"+title, http.StatusFound)s
		return
	}
	renderTemplate(w, "view", p)
}

func saveAction(w http.ResponseWriter, r *http.Request) {
	title := r.URL.Path[len("/save/"):]
	body := r.FormValue("body")
	p := &Page{Title: title, Body: []byte(body)}
	err := p.save()
	if err != nil {
		http.Error(w, err.Error(), http.StatusInternalServerError)
		return
	}
	http.Redirect(w, r, "/view/"+title, http.StatusFound)
}

func editAction(w http.ResponseWriter, r *http.Request) {
	title := r.URL.Path[len("/edit/"):]
	p, err := loadPage(title)
	if err != nil {
		log.Printf("File '%s' doesn't exist, %v. Creating it. ", title, err)
		p = &Page{Title: title}
	}
	renderTemplate(w, "edit", p)
}
