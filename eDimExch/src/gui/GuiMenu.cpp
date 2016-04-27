/*****************************************************************
 * $Id: GuiMenu.cpp 7 2007-05-22 15:03:42Z makhtar $
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
#include "GuiMenu.hpp"

/** Menubar implementation */
AbstractMenu::AbstractMenu(QWidget *papa)
        : QMenuBar(papa)
{
    File = new QMenu("&File");
    fileOpen = new QAction("&Open Key File...", this);
    //    fileOpen->setEnabled(false);
    fileSave = new QAction("&Save Connection Settings", this);
    //    fileSave->setEnabled(false);
    fileQuit = new QAction("&Quit", this);
    File->addAction(fileOpen);
    File->addAction(fileSave);
    File->addAction(fileQuit);
    this->addMenu(File);

    Control = new QMenu("&Control");
    ctrlConnect = new QAction("C&onnect", this);
    ctrlDisconnect = new QAction("D&isconnect", this);
    //    ctrlDisconnect->setEnabled(false);
    ctrlUpload = new QAction("&Upload Selected Files", this);
    //    ctrlStartUpload->setEnabled(false);
    ctrlDownload = new QAction("&Download Selected Files", this);
    //    ctrlStartDownload->setEnabled(false);
    ctrlCancel = new QAction("&Cancel Current Transfers", this);
    //    ctrlCancelTransfer->setEnabled(false);
    Control->addAction(ctrlConnect);
    Control->addAction(ctrlDisconnect);
    Control->addAction(ctrlUpload);
    Control->addAction(ctrlDownload);
    Control->addAction(ctrlCancel);
    this->addMenu(Control);

    View = new QMenu("&View", this);
    vwToggleViewMode = new QAction("&Toggle View Mode", this);
    vwShowHidden = new QAction("Show &Hidden Files", this);
    //    vwShowHidden->setEnabled(false);
    View->addAction(vwToggleViewMode);
    View->addAction(vwShowHidden);
    this->addMenu(View);

    Bookmark = new QMenu("&Bookmark", this);
    bmarkAdd = new QAction("&Add", this);
    bmarkEdit = new QAction("&Edit", this);
    bmarkImport = new QAction("&Import...", this);
    bmarkExport = new QAction("&Export...", this);
    Bookmark->addAction(bmarkAdd);
    Bookmark->addAction(bmarkEdit);
    Bookmark->addAction(bmarkImport);
    Bookmark->addAction(bmarkExport);
    this->addMenu(Bookmark);

    Tools = new QMenu("&Tools", this);
    toolTerminal = new QAction("&Terminal", this);
    toolMonitor = new QAction("&Monitor", this);
    Tools->addAction(toolTerminal);
    Tools->addAction(toolMonitor);
    this->addMenu(Tools);

    Settings = new QMenu("&Settings", this);
    settingConfig = new QAction("&Configuration", this);
    settingAppear = new QAction("&Appearance", this);
    Settings->addAction(settingConfig);
    Settings->addAction(settingAppear);
    this->addMenu(Settings);

    Help = new QMenu("&Help", this);
    hlpAbout = new QAction("&About", this);
    hlpUserManual = new QAction("User &Manual", this);
    hlpBWReport = new QAction("Bug, Wish &Report", this);
    Help->addAction(hlpAbout);
    Help->addAction(hlpUserManual);
    Help->addAction(hlpBWReport);
    this->addMenu(Help);
}
