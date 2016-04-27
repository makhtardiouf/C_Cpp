/*****************************************************************
 * $Id: gui.cpp 7 2007-05-22 15:03:42Z makhtar $
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

/* GUI implementation */
#include "gui.hpp"

/** Constructor for the GUI object */
Gui::Gui(QWidget* papa)
        : QMainWindow(papa)
{
    using namespace std;

    this->setWindowIcon(QIcon(QString::fromUtf8(":/img/edimLogo01-1.png")));

    QFont menuFont = QFont();
    //menuFont.setBold(true);
    menuFont.setPointSize(13);

    // Top part
    Menu = new AbstractMenu();
    Menu->setFont(menuFont);

    // Central part
    QWidget* centralWidg = new QWidget();

    QSpacerItem* MenuTabSpacer = new QSpacerItem(30, 40);

    TabGroup = new QTabWidget(centralWidg);
    Sftp = new AbstractSftp();
    TermEmu = new AbstractTermEmu();

    TabGroup->addTab(Sftp, "SFTP");
    TabGroup->addTab(TermEmu, "Terminal Emulator");

    // Bottom part
    connectBt = new QPushButton("C&onnect");
    connectBt->setToolTip("Connect to remote host");
    connectBt->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    cancelBt = new QPushButton("C&ancel");
    cancelBt->setEnabled(false);
    cancelBt->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    concancBt = new QStackedWidget();
    concancBt->addWidget(connectBt);
    concancBt->addWidget(cancelBt);
    concancBt->setCurrentWidget(connectBt);
    concancBt->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    disconnectBt = new QPushButton("D&isconnect");
    disconnectBt->setEnabled(false);
    disconnectBt->setToolTip("Disconnect from remote host");
    disconnectBt->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    quitBt = new QPushButton("&Quit");
    quitBt->setToolTip("Exit "APP_NAME);
    quitBt->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    info = new QStackedWidget();

    msgField = new QTextEdit(info);
    msgField->setReadOnly(true);
    //  msgField->setMaximumHeight(50);
    msgField->setSizePolicy(QSizePolicy::Expanding,
                            QSizePolicy::Expanding);
    msgField->append(APP_DEFINITION": Ready");

    pgress = new QProgressBar(info);
    pgress->setMaximumHeight(25);
    pgress->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    pgress->setTextVisible(true);

    info->addWidget(msgField);
    info->addWidget(pgress);
    info->setCurrentWidget(msgField);
    info->setMaximumHeight(100);

    QHBoxLayout* controlBtsLayout = new QHBoxLayout();
    controlBtsLayout->addWidget(concancBt);
    controlBtsLayout->addWidget(disconnectBt);
    controlBtsLayout->addWidget(quitBt);

    QGridLayout* overallLayout = new QGridLayout(centralWidg);
    overallLayout->setSpacing(10);
    overallLayout->setMargin(5);
    overallLayout->addItem(MenuTabSpacer, 0, 0);
    overallLayout->addWidget(TabGroup, 1, 0);
    overallLayout->addLayout(controlBtsLayout, 2, 0);
    overallLayout->addWidget(info, 3, 0);

    setMenuBar(Menu);
    setCentralWidget(centralWidg);
    SetAesthetics();
    SetCallbacks();
    sshSession = NULL;
    sftpSession = NULL;

    chdir(QDir::homePath().toStdString().c_str());
    Sftp->host->setFocus();
}
