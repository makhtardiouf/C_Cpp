

#include <stdio.h>
#include "malib.h"
#include "socket.h"

int main(void)
{
    init_socket();
    create_socket("localhost", 8349, "tcp", 1);
    end_socket();

    return 0;
}


