/*****************************************************************
 * $Id: cli.cpp 7 2007-05-22 15:03:42Z makhtar $
 * Copyright (C) 2006-2007 Makhtar Diouf
 * elmakdi@users.sourceforge.net
 *
 * -You can redistribute and/or modify this program
 *  under the terms of the GNU General Public License version 2.
 *  See the file COPYING for further information.
 *
 * -Vous pouvez redistribuer et/ou modifier ce programme
 *  sous les termes de la license GNU General Public version 2.
 *  Voir le fichier COPYING pour plus d'information.
 ****************************************************************/

/* Implementation of the Command Line Interface*/
#include "edimexch.h"
#include "cli.hpp"
#include <string>
#include <iostream>
extern "C"
{
#include <getopt.h>
}

const char*
Cli::Initialize(int argc, char** argv)
{
    using namespace std;
    int _option;
    int opt_index = 0;
    //   char* edimopts[] = {"gui", "tui", "version", "help", NULL};

    pair<const char*, char> gui = make_pair("gui", 'g');
    pair<const char*, char> tui = make_pair("tui", 't');
    pair<const char*, char> version = make_pair("version", 'V');
    pair<const char*, char> help = make_pair("help", 'h');

    static struct option long_opt[] = {

                                          {
                                              gui.first, no_argument,
                                              0, gui.second
                                          },
                                          {tui.first, no_argument,
                                           0, tui.second},
                                          {version.first, no_argument,
                                           0, version.second},
                                          {help.first, no_argument,
                                           0, help.second},
                                          {0, 0, 0, 0}
                                      };

    // reset the current option number error
    opterr = 0;
    guiEnabled = true;
    tuiEnabled = false;

    while ( (_option = getopt_long(argc, argv,
                                   "gtVh", long_opt,
                                   &opt_index)) != -1 ) {
        switch (_option) {
        case 'g':
            break;

        case 't' :
            guiEnabled = false;
            tuiEnabled = true;
            exit(EXIT_SUCCESS);

        case 'V':
            guiEnabled = false;
            slowcout("\n"APP_NAME" version: "APP_VERSION"\n");
            exit(EXIT_SUCCESS);

        case 'h':
            guiEnabled = false;
//             inithis();
            clearconsole();
            fflush(stderr);
            Usage(argv);
            exit(EXIT_SUCCESS);

        default :
            guiEnabled = true;
            cerr<< "Invalid argument: " << argv[optind - 1] << endl;
            Usage(argv);
            break;
        }
    }

    // Check the remaining arguments to find a possible initial url
    while (optind < argc) {
        string url = string(argv[optind++]);
        if (!url.empty())
            return (const char*)strdup(url.c_str());
    }
    return  NULL;
}

int
Cli::Usage(char** argv, bool wait_for_input)
{
    using namespace std;

    char* menu[] = {
                       "-g, --gui launch the Graphical User "
                       "Interface(default)",
                       "-t, --tui launch the Textual User Interface",
                       "-V, --version print version number of "APP_NAME,
                       "-h, --help  print this help message",
                       NULL
                   };

    Present();
    cerr<<"\n\nUsage: " << argv[0] << " [option...] HOSTNAME\n\n";
    slowcout("Available options: \n");
    if ( !wait_for_input ) {
        for (int i = 0; menu[i]; i++) {
            slowcout(menu[i]);
            cout<< '\n' ;
        }
        return EXIT_SUCCESS;
    } else
        return show_menu(menu);
}

void
Cli::Present()
{
    fflush(stderr);
    slowcout("\n\t"APP_NAME"\n"
             APP_DEFINITION
             "\nVersion:\t"APP_VERSION"\n"
             "Author:\t"AUTHOR"\n"
            );
}

void
Cli::LaunchTui()
{
    if (tuiEnabled) {
        //char* tui = "edimtui";
        clearconsole();
        Present();
        pausethis(1);
        slowcout("\n\nThe textual interface of this program is "
                 "under construction\n\n");

        // fork the TUI
        //system(tui);
    }
}
