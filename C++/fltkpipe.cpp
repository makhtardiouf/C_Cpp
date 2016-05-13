#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Text_Display.H>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
// c++ `fltk-config --cxxflags` fltkpipe.cpp -std=c++11  -lfltk -lXext -lX11 -lm

// fltk-ttys - Open several processes, display their output in fltk widgets
// Greg Ercolano 02/21/2005 1.00

Fl_Text_Display *G_disp[3]; // one display per child
Fl_Text_Buffer *G_buff[3];  // one buffer per child
int G_outfd[3];             // read pipe for child's stderr, one per child
pid_t G_pids[3];            // pid for each child

// Start child process, makes a read pipe to its stderr
void start_child(int t) {
  int out[2];
  pipe(out);
  switch ((G_pids[t] = fork())) {
  case -1: // Error
    close(out[0]);
    close(out[1]);
    perror("fork()");
    exit(1);
    
  case 0: // Child
    close(out[0]);
    dup2(out[1], 2);
    close(out[1]);
    
    switch (t) {
      
    case 0:
      execlp("/bin/sh", "sh", "-c", "ps auxww 1>&2", 0);
      perror("execlp(ps)");
      exit(1);
      
    case 1:
      execlp("/bin/sh", "sh", "-c",
             "perl -e 'for($t=0; sleep(1); $t++)"
             "{print STDERR rand().\"\\n\"; if ($t>5) {kill(9,$$);}}' 1>&2",
             0);
      perror("execlp(perl)");
      exit(1);
      
    case 2:
      execlp("/bin/sh", "sh", "-c", "(who; ping -c 8 localhost) 1>&2", 0);
      perror("execlp(ls/ping)");
      exit(1);
    default:
      exit(1);
    }  
    
  default: // Parent
    G_outfd[t] = out[0];
    close(out[1]);
    return;
  }
}

// Data ready interrupt
void data_ready(int fd, void *data) {
  
  auto t = reinterpret_cast<intptr_t>(data);
  char s[4096];
  int bytes = read(fd, s, 4096 - 1);
  // fprintf(stderr, "Data ready for %d) pid=%ld fd=%d bytes=%d\n", t,
  // (long)G_pids[t], fd, bytes);
  
  if (bytes == -1) { // ERROR
    perror("read()");
    
  } else if (bytes == 0) { // EOF
  
    G_buff[t]->append("\n\n*** EOF ***\n");
    int status;
    if (waitpid(G_pids[t], &status, WNOHANG) < 0) {
      sprintf(s, "waitpid(): %s\n", strerror(errno));
      
    } else {
      
      if (WIFEXITED(status)) {
        
        sprintf(s, "Exit=%d\n", WEXITSTATUS(status));
        close(fd);
        Fl::remove_fd(fd);
        G_pids[t] = -1;
        
      } else if (WIFSIGNALED(status)) {
        sprintf(s, "Killed with %d\n", WTERMSIG(status));
        close(fd);
        Fl::remove_fd(fd);
        G_pids[t] = -1;
        
      } else if (WIFSTOPPED(status)) {
        sprintf(s, "Stopped with %d\n", WSTOPSIG(status));
      }
    } 
    
    G_buff[t]->append(s);
    
  } else { // DATA
    s[bytes] = 0;
    G_buff[t]->append(s);
  }
}

// Clean up if someone closes the window
void close_cb(Fl_Widget *, void *) {
  
  printf("Killing child processes..\n");
  for (int t = 0; t < 3; t++) {
    if (G_pids[t] == -1)
      continue;
    kill(G_pids[t], 9);
  }
  printf("Done.\n");
  exit(0);
}

int main() {
  Fl_Double_Window win(620, 520);
  win.callback(close_cb); // kill children if window closed
  
  // Start children, one tty for each
  for (int t = 0; t < 3; t++) {
    start_child(t);
    G_buff[t] = new Fl_Text_Buffer();
    G_disp[t] = new Fl_Text_Display(10 + t * 200, 10, 200, 500);
    G_disp[t]->buffer(G_buff[t]);
    G_disp[t]->textfont(FL_COURIER);
    G_disp[t]->textsize(12);
    Fl::add_fd(G_outfd[t], data_ready, (void *)t);
  }
  win.resizable(win);
  win.show();
  return (Fl::run());
}
