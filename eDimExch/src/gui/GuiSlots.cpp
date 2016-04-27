/*****************************************************************
 * $Id: GuiSlots.cpp 7 2007-05-22 15:03:42Z makhtar $
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
/* Implementation of slots and other methods */
#define _BSD_SOURCE

#include "gui.hpp"
#include "SftpSlots.cpp"
#include <fcntl.h>  // open()
#include <unistd.h>  // close()
#include <sys/stat.h>

void
Gui::AddToList(QString file)
{
    QListWidgetItem *item = new QListWidgetItem();
    item->setText(file);

    // QPixmap pixmap(urlInfo.isDir() ? "img/folder.png" : "img/file.png");
    QPixmap filePixmap("img/file.png");
    item->setIcon(filePixmap);
    //    isDir[urlInfo.name()] = urlInfo.isDir();
    Sftp->remotefs->addItem(item);

    if (!Sftp->remotefs->currentItem()) {
        Sftp->remotefs->setCurrentItem(Sftp->remotefs->item(0));
        Sftp->remotefs->setEnabled(true);
    }
}

void
Gui::Cancel()
{}

void
Gui::Download()
{
    using namespace std;

    QString basedir = QString(sftp_canonicalize_path(sftpSession, "./"));
    QString name = Sftp->remotefs->currentItem()->text();
    QString target = basedir.append("/").append(name);
    QString mirrorFile = QDir::currentPath().append("/dim").append(name);

    char* c_target = strdup(target.toStdString().c_str());
    char* c_mirror = strdup(mirrorFile.toStdString().c_str());

    ShowMsg(QString("Requested remote file: ").append(target)
            .append("  Transferring data to: ").append(mirrorFile));

    sftp_file remoteFile = sftp_open(sftpSession, c_target, O_RDONLY, NULL);

    if (remoteFile) {
        char fileData[8000];
        int len = 1;
        int localFile = open(c_mirror, O_WRONLY | O_CREAT, S_IRUSR);

        if (localFile >= 0) {
            QApplication::setOverrideCursor(Qt::WaitCursor);

            while ( (len = sftp_read(remoteFile, fileData, 4096)) > 0) {
                if (write(localFile, fileData, len) != len)
                    SysError("write");
            }
            //fchmod(localFile, S_IRUSR | S_IWUSR | S_IRGRP);
            //fchmod(localFile, S_IRUSR | S_IWUSR);
            // !!!! can't find close's namespace ?
            //close(localFile);
            sftp_close(remoteFile);
            ShowMsg("Download done...");
            UpdateLocalFs();
        } else
            SysError("open");
    } else
        ShowMsg(SftpError());

    QApplication::restoreOverrideCursor();
}

int
Gui::GetLoginMethod() const
{
    // tmp
    if (Sftp->detailsWin->passMeth->isChecked())
        return PASSW;
    else if (Sftp->detailsWin->kbdIntMeth->isChecked())
        return KBDINTERACT;
    else if (Sftp->detailsWin->pubKeyMeth->isChecked())
        return PUBKEY;
    else
        return PASSW;
}

void
Gui::Logout()
{
    using namespace std;
    QApplication::restoreOverrideCursor();

    if (sshSession != NULL) {
        if (sftpSession != NULL)
            sftp_free(sftpSession);

        ssh_disconnect(sshSession);

        Sftp->remotefs->clear();
        ShowMsg("Disconnected");
        connectBt->setEnabled(true);
        disconnectBt->setEnabled(false);
        Menu->ctrlDisconnect->setEnabled(false);
        Sftp->detailsWin->passw->clear();
        SetTitle();
    } else
        ShowMsg(SftpError());
}

void
Gui::Progress(int fake)
{
    pgress->setTextVisible(true);
    pgress->setMaximum(100);

    for (int i = fake = 0; i<= 100; i++)
        pgress->setValue(i);

    pgress->setValue(0);
    info->setCurrentWidget(msgField);
}

void
Gui::Progress(int i, bool showText)
{
    pgress->setTextVisible(showText);
    pgress->setValue(i);
}

void
Gui::TellAbout()
{
    static QString contents =
        QString(tr("<center><IMG SRC=\":/img/edimLogo01-1.jpg\">\
                   <h4>eDimExch<br>APP_DEFINITION<br>\
                   APP_VERSION<br>Copyright (C) 2006-2007 Makhtar Diouf<br></h4>\
                   Using <b><a href=\"http:trolltech.com\">Qt</a> QT_VERSION</b>\
                   <br><br>Please, send suggestions and bug reports to \
                   <a href=\"mailto:elmakdi@users.sourceforge.net\">\
                   elmakdi@users.sourceforge.net</a><br><p>\
                   You can redistribute and/or modify this open source \
                   software under the terms of the GNU General PublicLicense \
                   version 2.<br>See the file COPYING for furtherinformation.\
                   </p><center>"));

    contents.replace(tr("APP_DEFINITION"), APP_DEFINITION);
    contents.replace(tr("APP_VERSION"), APP_VERSION);
    contents.replace(tr("QT_VERSION"), QT_VERSION_STR);

    // Make it show up fast
    static QDialog* msgDialog = new QDialog(this);
    infoDialog.setupUi(msgDialog);
    infoDialog.infoMsg->setHtml(contents);
    infoDialog.infoMsg->setReadOnly(true);
    msgDialog->setWindowTitle(tr("About eDimExch"));
    msgDialog->show();
}

void
Gui::UpdateLocalFs()
{
    QString path = QDir::currentPath();
    Sftp->localfs->setRootIndex(Sftp->localfsModel->index(path));
    Sftp->localfs->repaint();

    Sftp->localPath->insertItem(0, path);
    Sftp->localPath->setCurrentIndex(0);
    ShowMsg(QString("Changed local path to: ").append(path));
}

void
Gui::Retry()
{
    QApplication::restoreOverrideCursor();
    concancBt->setCurrentWidget(connectBt);
    connectBt->setEnabled(true);
    ShowMsg(SftpError());
    ShowMsg("Please verify your login information");
    Sftp->detailsWin->show();
    // Sftp->detailsWin->passw->clear();
    Sftp->detailsWin->passw->setFocus();
}

void
Gui::SetAesthetics()
{
    qApp->setStyle(new QPlastiqueStyle());

    setWindowTitle(APP_NAME);
    setBackgroundRole(QPalette::Button);

    // #ifdef __WIN32__
    QFont w32Font = QFont();
    w32Font.setStyleHint(QFont::AnyStyle);
    w32Font.setStyle(QFont::StyleNormal);
    //    w32Font.setWeight(QFont::DemiBold);
    w32Font.setPointSize(13);
    //#endif
    setFont(w32Font);

    setWindowState(Qt::WindowMaximized);
    setMinimumSize(minimumSizeHint());
    //move(0, 0);
}

void
Gui::SetCallbacks()
{
    QObject::connect(Menu->hlpAbout, SIGNAL(triggered()), SLOT(TellAbout()));

    QObject::connect(Menu->ctrlConnect, SIGNAL(triggered()),
                     connectBt, SIGNAL(clicked()));

    QObject::connect(Menu->ctrlDisconnect, SIGNAL(triggered()),
                     disconnectBt, SIGNAL(clicked()));

    QObject::connect(Menu->fileQuit, SIGNAL(triggered()),
                     quitBt, SIGNAL(clicked()));

    QObject::connect(Menu->fileOpen, SIGNAL(triggered()),
                     Sftp->detailsWin, SLOT(SelectKey()));

    QObject::connect(this->connectBt, SIGNAL(clicked()), SLOT(Login()));

    QObject::connect(this->cancelBt, SIGNAL(clicked()), SLOT(Cancel()));

    QObject::connect(disconnectBt, SIGNAL(clicked()), SLOT(Logout()));

    QObject::connect(quitBt, SIGNAL(clicked()), SLOT(close()));

    QObject::connect(Sftp->host, SIGNAL(textChanged(const QString &)),
                     SLOT(EnableConnectBt()));

    QObject::connect(Sftp->detailsWin, SIGNAL(accepted()),
                     this->connectBt, SIGNAL(clicked()));

    QObject::connect(Sftp->cdUpLocBt, SIGNAL(clicked()),
                     SLOT(CdUpLocal()));

    QObject::connect(Sftp->downloadBt, SIGNAL(clicked()),
                     SLOT(Download()));
}

void
Gui::SetTitle(std::string postfix)
{
    using namespace std;

    if (postfix.empty())
        setWindowTitle(APP_NAME);
    else {
        ostringstream title;
        title << APP_NAME"@" << postfix << ends ;
        setWindowTitle(title.str().c_str());
        // seek the beginning of the buffer after every call
        title.seekp(0, ios::beg);
    }
}

void
Gui::ShowMsg(QString msg)
{
    info->setCurrentWidget(msgField);
    msgField->append(msg);
    msgField->scrollToAnchor(msg);
}
