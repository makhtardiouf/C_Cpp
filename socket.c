/*
$Id: socket.c 5 2007-03-31 15:04:06Z Makhtar $
Implementation of socket-programming related functions
*/

#include "socket.h"

enum
{
    NOOP ,
    CONNECT ,
    BIND
};


int init_socket(void)
{
#ifdef __unix__
    return EXIT_SUCCESS;
#endif

#ifdef __WIN32__

    WORD wVersionRequested;
    WSADATA wsaData;
    wVersionRequested = MAKEWORD( 2,  0);
    /** zero means no error */
    return WSAStartup( wVersionRequested,  &wsaData);

#endif

}


int end_socket(void)
{
#ifdef __unix__
    return EXIT_SUCCESS;
#endif

#ifdef __WIN32__

    return WSACleanup();
#endif
}


int get_socket_name(struct sockaddr_in *name,
                    char *hostname, char *hostaddr)
{
    struct hostent *hp;
    hp = NULL;
    int i;

    hp = gethostbyaddr((char *)&(name->sin_addr),
                       sizeof(name->sin_addr), AF_INET);

    if (hp == NULL)
        return EXIT_FAILURE;

    strcpy(hostname, hp->h_name);

    for (i = 0; hp->h_addr_list[i]; i++)
    {
        sprintf(hostaddr, "%d.%d.%d.%d",
                (unsigned char)hp->h_addr_list[i][0],
                (unsigned char)hp->h_addr_list[i][1],
                (unsigned char)hp->h_addr_list[i][2],
                (unsigned char)hp->h_addr_list[i][3]);
    }

    /* OR */
    /*
     sprintf(hostaddr, "%d.%d.%d.%d", 
     name->sin_addr.S_un.S_un_b.s_b1,
     name->sin_addr.S_un.S_un_b.s_b2, 
     name->sin_addr.S_un.S_un_b.s_b3, 
     name->sin_addr.S_un.S_un_b.s_b4);
    */
    return EXIT_SUCCESS;
}


SOCKET create_socket(char *hostname, unsigned short port,
                     char *protocol, int action)
{
    SOCKET s;
    struct hostent *hp;
    struct sockaddr_in hostaddr_in;

    memset(&hostaddr_in, 0, sizeof(struct sockaddr_in));
    hp = NULL;
    s = INVALID_SOCKET;

    hp = gethostbyname(hostname);

    if (strcmp(protocol, "udp")== 0)
        s = socket(AF_INET, SOCK_DGRAM, 0);
    else
        if (strcmp(protocol, "tcp")== 0)
            s = socket(AF_INET, SOCK_STREAM, 0);
        else
            return INVALID_SOCKET;

    hostaddr_in.sin_family = AF_INET;

    hostaddr_in.sin_addr.s_addr = ((struct in_addr *)(hp->h_addr))->s_addr;

    hostaddr_in.sin_port = htons(port);

    switch (action) {

    case BIND:

        if ( bind(s, (struct sockaddr *) &hostaddr_in, sizeof(struct sockaddr_in)))
            return INVALID_SOCKET;

        break;

    case CONNECT:

        if ( connect(s, (struct sockaddr *)&hostaddr_in, sizeof(struct sockaddr_in)))
            return INVALID_SOCKET;

        break;

    default:
        return s;
    }

    return s;
}


SOCKET create_socket_by_service(char *hostname, char *servicename,
                                char *proto, int action)
{
    struct servent* sp = getservbyname(servicename, proto);

    if (sp == NULL)
        return INVALID_SOCKET;

    return create_socket(hostname, sp->s_port, proto, action);
}


SOCKET broad_cast_socket(void)
{
    int optval = 1;
    SOCKET s;

    s = socket(AF_INET, SOCK_DGRAM, 0);

    if (setsockopt(s, SOL_SOCKET, SO_BROADCAST,
                   (SOCKOPT_TYPE *)&optval, sizeof(int)))
        return INVALID_SOCKET;

    return s;
}


SOCKET async_socket(int type)
{
    int optval;
    SOCKET s;
    optval = 1;

    s = socket(AF_INET, type, 0);

    if (ioctlsocket(s, FIONBIO, (IOCTL_TYPE *)&optval))
        return INVALID_SOCKET;

    return s;
}


SOCKET sync_socket(int type)
{
    int optval;
    SOCKET s;
    optval = 0;

    s = socket(AF_INET, type, 0);

    if (ioctlsocket(s, FIONBIO, (IOCTL_TYPE *)&optval))
        return INVALID_SOCKET;

    return s;
}


int async_recv(SOCKET s, char *msg, int msg_size, int timeout)
{
    clock_t endtime;
    int rec;

    endtime = (clock_t)( ((double)timeout)/1000.0)
              * CLOCKS_PER_SEC + clock();

    do {
        rec = recv(s, msg, msg_size, 0);
    } while (rec == -1&&endtime > clock());

    return rec;
}


int async_send(SOCKET s, char *msg, int msg_size, int timeout)
{
    clock_t endtime;
    int snd;

    endtime = (clock_t)( ( (double)timeout)/1000.0)
              * CLOCKS_PER_SEC + clock();

    do {
        snd = send(s, msg, msg_size, 0);
    } while ( snd == -1&&endtime > clock());

    return snd;
}


int async_recv_from(SOCKET s, char *msg, int msg_size, struct sockaddr_in *addr, int timeout)
{
    clock_t endtime;
    int rec;
    int addr_size;
    addr_size = sizeof(struct sockaddr_in);

    endtime = (clock_t)(((double)timeout)/1000.0) * CLOCKS_PER_SEC + clock();

    do
    {
        rec = recvfrom(s, msg, msg_size, 0, (struct sockaddr *)addr,
                       (socklen_t*)&addr_size);
    } while (rec == -1&&endtime > clock());

    return rec;
}


int async_send_to(SOCKET s, char *msg, int msg_size,
                  struct sockaddr_in *addr, int timeout)
{
    clock_t endtime;
    int snd;

    endtime = (clock_t)( ((double)timeout)/1000.0) * CLOCKS_PER_SEC + clock();

    do
    {
        snd = sendto( s, msg, msg_size, 0, (struct sockaddr *)addr,
                      sizeof(struct sockaddr_in));
    } while (snd == -1&&endtime > clock());

    return snd;
}


int recv_all(SOCKET s, char *msg, int msg_size)
{
    int rec;
    int i = 0;

    do {
        rec = recv(s, &msg[i], msg_size - i, 0);
        i += rec;
    } while (rec < msg_size&&rec > 0);

    return rec;
}


int send_all(SOCKET s, char *msg, int msg_size)
{
    int snd;
    int i = 0;

    do {
        snd = send(s, &msg[i], msg_size - i, 0);
        i+= snd;
    } while (snd < msg_size&&snd > 0);

    return snd;
}


SOCKET async_accept(SOCKET s, struct sockaddr_in *addr, int timeout)
{
    clock_t endtime;
    SOCKET as;
    int addr_len;

    endtime = (clock_t)(((double)timeout)/1000.0)* CLOCKS_PER_SEC + clock();

    addr_len = sizeof(struct sockaddr_in);
    as = INVALID_SOCKET;

    endtime = (clock_t)(((double)timeout)/1000.0) * CLOCKS_PER_SEC + clock();

    do
    {
        as = accept(s, (struct sockaddr *)addr, (socklen_t*)&addr_len);
    } while (as == INVALID_SOCKET&&endtime > clock());

    return as;
}


int async_connect(SOCKET s,struct sockaddr_in *addr, int timeout)
{
    clock_t endtime;
    int retval;

    endtime = (clock_t)(((double)timeout)/1000.0)* CLOCKS_PER_SEC + clock();

    do
    {
        retval = connect(s, (struct sockaddr *)addr, sizeof(struct sockaddr_in));
    } while (retval && endtime>clock());

    return retval;
}
