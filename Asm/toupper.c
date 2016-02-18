/*
$Id$

*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int fdin, fdout;
    char buf[500];
    ssize_t readbuff;

    fprintf(stderr, "sizeof char %d\n", sizeof(char));
    fprintf(stderr, "argc @ %x\n", &argc);
    fprintf(stderr, "argv[0] @ %x\n", &argv[0]);
    fprintf(stderr, "argv[1] @ %x\n", &argv[1]);
    fprintf(stderr, "argv[2] @ %x\n", &argv[2]);

    fdin = open(argv[1], 0);
    fdout = open(argv[2], 03101);
    fprintf(stderr, "fdin @ %x\n", &fdin);
    fprintf(stderr, "fdout @ %x\n", &fdout);

    do {
    readbuff = read(fdin, buf, sizeof(buf));
    write(fdout, buf, readbuff);
    } while(readbuff > 0);

    close(fdin);
    close(fdout);
    return 0;
}
