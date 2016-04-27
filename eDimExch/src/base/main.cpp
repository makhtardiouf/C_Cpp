/*****************************************************************
 * $Id: main.cpp 7 2007-05-22 15:03:42Z makhtar $
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
#include "gui.hpp"
#include "cli.hpp"
#include <exception>
#include <csignal>

/**
Check the argument list.
Setup signal handling hooks.
Initialize and start the appropriate user interface.
*/
int
main(int argc, char** argv)
{
    using namespace std;

    try {
        errno = 0;

        if (signal(SIGSEGV, handle_signal) == SIG_ERR)
            perror("\nSIGSEGV signal handler");
        if (signal(SIGTERM, handle_signal) == SIG_ERR)
            perror("\nSIGTERMsignal handler");

        QApplication::setDesktopSettingsAware(true);
        Cli* cli = new Cli();
        const char* host = cli->Initialize(argc, argv);

        QApplication* app = new QApplication(argc, argv, cli->EnableGui());
        app->setApplicationName(APP_NAME);
        Q_INIT_RESOURCE(edim);

        if (cli->EnableGui()) {
            Gui* gui = new Gui();
            gui->SetHostname(host);
            gui->show();
        } else
            cli->LaunchTui();

        return app->exec();
    } catch (std::exception &e) {
        //temp
        cerr<< "\nThe following exception was caught: "
        << e.what() << endl;
    } catch (...) {
        // temp
        cerr<< "\nUnknown exception caught..." << endl;
    }
    return EXIT_SUCCESS;
}
