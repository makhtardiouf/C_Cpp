// https://golang.org/doc/effective_go.html#web_server
// Augmented by Makhtar Diouf

package main

import (
	"flag"
	"html/template"
	"log"
	"net/http"
	"time"
)

var addr = flag.String("addr", ":9000", "http service address") // Q=17, R=18

var templ = template.Must(template.New("qr").Parse(templateStr))
var numRequests = 0
var curTime = time.Now().String()

func main() {
	flag.Parse()
	http.Handle("/", http.HandlerFunc(QR))
	err := http.ListenAndServe(*addr, nil)
	if err != nil {
		log.Fatal("ListenAndServe:", err)
	}
	_ = time.Now()

	log.Println("Open the link http://localhost:9000")

}

func QR(w http.ResponseWriter, req *http.Request) {
	log.Printf("Received request %d from %s\n", numRequests, req.UserAgent())
	templ.Execute(w, req.FormValue("str"))

	numRequests++
	curTime = time.Now().String()
}

const templateStr = `
<html>
<head>
<title>QR Link Generator</title>
<link rel="stylesheet" href="http://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css">
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js"></script>
        <script src="http://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/js/bootstrap.min.js"></script>

</head>
<body>
<div class="container-fluid">
<div class="jumbotron col-md-4">

<p> Enter a text to encode: </p>

<form action="/" name=f method="GET" class="form-horizontal">

<input maxLength=1024 size=70 name="str" value="" title="Text to QR Encode" class="form-control" >
<br>
<input type="submit" value="Show QR" name="qr" class="btn btn-primary">
</form>
</div>

<div class="col-md-4">
{{if .}}
<img src="http://chart.apis.google.com/chart?chs=300x300&cht=qr&choe=UTF-8&chl={{.}}" />
<br>
{{.}}
<br>
{{end}}

</div>
{{.numRequests}} requests received.<br>
{{.curTime}}

</div>
</body>
</html>
`
