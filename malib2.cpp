/* $Id: malib2.cpp 9 2007-07-11 08:22:53Z Makhtar $

Implementation of c++ utility functions */

#include "malib.h"
#include <string>


/* Get the execee's name and arguments then fork it */
int spawn(const char* cmd[] )
{
    std::string command(cmd[0]);

    for (int i = 1; cmd[i] != NULL; ++i) {
        command.append(" -");
        command.append(cmd[i]);
    }

    FILE* process;
    if ( (process = popen(command.c_str(), "w")) != NULL) {
        pclose(process);
        return EXIT_SUCCESS;
    }

    perror(cmd[0]);
    return EXIT_FAILURE;
}
