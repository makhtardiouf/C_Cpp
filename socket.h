/*
$Id: socket.h,v 71f8a7269804 1434171018.0-32400 makhtar $
Small crossplatform socket programming library.
Originally written by Ugo Varetto in the `Network programming
crash course' version 0.5.1 */

#ifndef SOCKET_H
#define SOCKET_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __WIN32__
#include <winsock2.h>
#include <process.h>

    typedef u_long IOCTL_TYPE;
    typedef char SOCKOPT_TYPE;
    typedef int socklen_t;
    /* typedef unsigned int pid_t; */

#elif defined __unix__
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <netdb.h>
#include <unistd.h>
#include <signal.h>

    typedef int SOCKET;
    typedef char IOCTL_TYPE;
    typedef void SOCKOPT_TYPE;

#define INVALID_SOCKET -1

#define closesocket(s) close(s)

#define ioctlsocket(s, cmd, argp) ioctl(s, cmd, argp)

#define Sleep(t) usleep(t*1000)

#endif

    static socklen_t addrLength = sizeof(struct sockaddr_in);

#define CLEAR_ADDR(addr) memset(addr, 0, addrLength)

#define sync_send(s, buffer, bufsize) async_send(s, buffer, bufsize, -1)

#define sync_recv(s, buffer, bufsize) async_recv(s, buffer, bufsize, -1)

#define sync_sendto(s, buffer, bufsize, addr) async_sendto(s, buffer, bufsize, addr, -1)

#define sync_recvfrom(s, buffer, bufsize, addr) async_recvfrom(s, buffer, bufsize, addr, -1)

#define sync_accept(s, addr) async_accept(s, addr, -1)

    /* functions to handle initialization and cleanup */
    extern int init_socket(void);
    extern int end_socket(void);

#define sockInit(void) init_socket(void)
#define sockEnd(void) end_socket(void)


    /* use inet_ntop()... instead of the following functions
     extern int inetAddrConvert(char *ascii_addr, char *addr); 
     extern int inetAddr(char *arg);
    */

    extern int get_socket_name(struct sockaddr_in *name,
                                   char *hostname, char *hostaddr);

    extern SOCKET create_socket(char *hostname, unsigned short port,
                                    char *protocol, int action);

    extern SOCKET create_socket_by_service(char *hostname, char *servicename,
                                               char *proto, int action);

    extern SOCKET broad_cast_socket(void);

    extern SOCKET sync_socket(int type);

    extern SOCKET async_socket(int type);

    extern int async_send(SOCKET s, char *buffer, int bufsize,
                              int timeout);

    extern int async_recv(SOCKET s, char *buffer, int bufsize,
                              int timeout);

    extern int async_recvfrom(SOCKET s, char *msg, int msg_size,
                                  struct sockaddr_in *addr, int timeout);

    extern int async_sendto(SOCKET s, char *msg, int msg_size,
                                struct sockaddr_in *addr, int timeout);

    extern int recv_all(SOCKET s, char *msg, int msg_size);

    extern int send_all(SOCKET s, char *msg, int msg_size);


    extern int async_connect(SOCKET s,  struct sockaddr_in *addr,
                                 int timeout);

    extern SOCKET async_accept(SOCKET s, struct sockaddr_in *addr,
                                   int timeout);
#ifdef __cplusplus
}
#endif
#endif
