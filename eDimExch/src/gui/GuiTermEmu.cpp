/*****************************************************************
 * $Id: GuiTermEmu.cpp 7 2007-05-22 15:03:42Z makhtar $
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

#include "GuiTermEmu.hpp"
# include <unistd.h>


/** Terminal emulator implementation */
AbstractTermEmu::AbstractTermEmu(QWidget* papa)
        : QWidget(papa)
{
    prompt = QString(APP_NAME"@");
    prompt.append(QHostInfo::localHostName());
    prompt.append("> ");

    QVBoxLayout* termLayout = new QVBoxLayout(this);
    QFont defFont = QFont();
    defFont.setBold(true);

    display = new QTextEdit();
    display->append(prompt);
    //display->setReadOnly(true);
    display->setFont(defFont);
    display->setPalette(ColorizeTermEmu());
    display->setCursor(Qt::IBeamCursor);
    display->setAcceptDrops(true);
    display->setSizePolicy(QSizePolicy::Expanding,
                           QSizePolicy::Expanding);
    termLayout->addWidget(display);
    this->setLayout(termLayout);
}


void AbstractTermEmu::RunCmd()
{
    //   char* buffer[4096];
    //test
    QString strCmd = "ls"; //display->text();
    const char* cmd = strCmd.toStdString().c_str();
    process = popen(strdup(cmd), "rw");
    if (process != NULL) {
        // fgets(*buffer, 512, process);
        // display->append(*buffer);
        pclose(process);
    } else
        display->append(strerror(errno));

    GetInput();
}


void AbstractTermEmu::GetInput()
{
    display->append(prompt);
}


void AbstractTermEmu::Activate()
{
    GetInput();
    //     if(process != NULL)
    //  //display->append(fgets(buffer, 4096, process));
    //     else
    // //    display->append(strerror(errno));
    //  free(command);
}


QPalette AbstractTermEmu::ColorizeTermEmu()
{
    QPalette pal;
    pal.setColor(QPalette::Active, QPalette::Text,
                 QColor(255, 255, 255));
    pal.setColor(QPalette::Active, QPalette::Base,
                 QColor(40, 40, 40));
    pal.setColor(QPalette::Active, QPalette::AlternateBase,
                 QColor(232, 232, 232));

    pal.setColor(QPalette::Inactive, QPalette::Text,
                 QColor(255, 255, 255));
    pal.setColor(QPalette::Inactive, QPalette::Base,
                 QColor(40, 40, 40));
    pal.setColor(QPalette::Inactive, QPalette::AlternateBase,
                 QColor(232, 232, 232));

    pal.setColor(QPalette::Disabled, QPalette::Text,
                 QColor(199, 199, 199));
    pal.setColor(QPalette::Disabled, QPalette::Base,
                 QColor(239, 239, 239));

    pal.setColor(QPalette::Disabled, QPalette::AlternateBase,
                 QColor(232, 232, 232));

    return pal;
}
