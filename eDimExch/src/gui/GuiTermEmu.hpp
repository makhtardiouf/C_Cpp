/*****************************************************************
 * $Id: GuiTermEmu.hpp 7 2007-05-22 15:03:42Z makhtar $
 * Copyright (C) 2006-2007 by Makhtar Diouf
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

/** Terminal emulator interface */

#ifndef GUITERMEMU_HPP
#define GUITERMEMU_HPP

#include "edimexch.h"
#include "qt.hpp"


class AbstractTermEmu : public QWidget
{
    Q_OBJECT

public:
    AbstractTermEmu(QWidget* papa = 0);

    char* command;
    char* buffer;
    FILE* process;

    QString prompt;
    QTextStream* shellInput;
    QLineEdit* input;
    QTextEdit* display;
    QStackedWidget* inout;

public slots:
    QPalette ColorizeTermEmu();
    void RunCmd();
    void GetInput();
    void Activate();
};
#endif
