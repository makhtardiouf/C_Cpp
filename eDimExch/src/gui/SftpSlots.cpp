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

/* Sftp related slots and other member functions' implementation */

#include "libssh/libssh.h"
#include "libssh/sftp.h"

void
Gui::ExecLoginMethod()
{
    switch (loginMethod) {
    case PASSW:
        if ( PasswLogin() != SSH_AUTH_SUCCESS )
            Retry();
        break;

    case KBDINTERACT:
        if ( InteractLogin() != SSH_AUTH_SUCCESS )
            Retry();
        break;

    case PUBKEY:
        if ( PubKeyLogin() != SSH_AUTH_SUCCESS )
            Retry();
        break;

    default:
        PasswLogin();
        break;
    }
}

int
Gui::InteractLogin()
{
  return 0;
    /*
       int status  = ssh_userauth_kbdint(sshSession, NULL, NULL);
       ShowMsg("Trying keyboard interactive login...");

       switch (status) {
       case SSH_AUTH_SUCCESS:
           break;

       case SSH_AUTH_DENIED:
           Retry();
           break;

       case SSH_AUTH_INFO:
           int numofprompts = ssh_userauth_kbdint_getnprompts(sshSession);
           for (int i = 0; i <= numofprompts; i++) {
               ShowMsg(ssh_userauth_kbdint_getname(sshSession));
               QString prompit = QInputDialog::getText(this,
                                                       ssh_userauth_kbdint_getinstruction(sshSession),
                                                       "Answer: ", QLineEdit::Normal);

               ssh_userauth_kbdint_setanswer(sshSession, i, strdup(prompit.toStdString().c_str()));

               if (ssh_userauth_kbdint(sshSession, NULL, NULL)
                       == SSH_AUTH_SUCCESS)
                   break;
           }
           break;
       }
       return status;
    */
}

int
Gui::ListRemoteFs()
{
    using namespace std;

    if ( ((sftpSession = sftp_new(sshSession)) != NULL) && (sftp_init(sftpSession) == 0) ) {
        sftp_dir sftpDir;

        if ( (sftpDir = sftp_opendir(sftpSession, "./")) != NULL) {
            int remoteFiles = 0;
            info->setCurrentWidget(pgress);

            while ( (sftpAttribs = sftp_readdir(sftpSession, sftpDir)) ) {
                AddToList(sftpAttribs->name);
                remoteFiles++;
                Progress(remoteFiles, false);
                sftp_attributes_free(sftpAttribs);
            }
            sftp_closedir(sftpDir);

            ShowMsg(QString("Logged in successfully."
                            " %1 items listed.").arg(remoteFiles));

            Sftp->uploadBt->setEnabled(true);
            Sftp->downloadBt->setEnabled(true);

            return remoteFiles;
        }
    }
    ShowMsg(SftpError());
    return -1;
}

void
Gui::Login()
{
    using namespace std;

    QUrl* Url = new QUrl(Sftp->host->text());

    if (Url->isEmpty())
        ShowMsg("Please enter a hostname");
    else if (Url->isValid()) {
        QApplication::setOverrideCursor(Qt::WaitCursor);
        ShowMsg(QString("Connecting to ").append(Host()).append("..."));

        socket = new QTcpSocket();
        socket->blockSignals(false);
        int fd = socket->socketDescriptor();

        ssh_options_set(sshSession, SSH_OPTIONS_USER , (const void*)User());
        ssh_options_set(sshSession, SSH_OPTIONS_HOST, (const void*)Host());
        ssh_options_set(sshSession, SSH_OPTIONS_PORT, (const void*)Port());
        ssh_options_set(sshSession, SSH_OPTIONS_FD, (const void*)fd);

        info->setCurrentWidget(pgress);
        Progress();

        if (ssh_connect(sshSession)) {
            ShowMsg(SftpError());
            ShowMsg("Please verify the connection parameters");
            // conCanBt->setCurrentWidget(connectBt);
        } else {
            concancBt->setCurrentWidget(cancelBt);
            connectBt->setEnabled(false);
            disconnectBt->setEnabled(true);
            Menu->ctrlDisconnect->setEnabled(true);
            SetTitle(Host());
            GetLoginMethod();
            ExecLoginMethod();
            ListRemoteFs();
        }
    } else {
        ShowMsg("Please verify the hostname");
    }

    QApplication::restoreOverrideCursor();
    concancBt->setCurrentWidget(connectBt);
}

int
Gui::PubKeyLogin()
{
  return 0;
    /*
       STRING* pubkey;
       PRIVATE_KEY* privkey;
       int type;

       ShowMsg("Trying login with public key...");
       pubkey = publickey_from_file("~/.ssh/id_dsa.pub", &type);

       if (ssh_userauth_offer_pubkey(sshSession, NULL, type, pubkey)
               == SSH_AUTH_SUCCESS) {
           QString pass = QInputDialog::getText(this,
                                                "Enter passphrase",
                                                "Passphrase: ",
                                                QLineEdit::Password);

           privkey = privatekey_from_file(sshSession, "~/.ssh/id_dsa", type,
                                          strdup(pass.toStdString().c_str()));

           return ssh_userauth_pubkey(sshSession, NULL, pubkey, privkey);
       } else
           ShowMsg(SftpError());

       // Last resort; automatic descovering of the pubkey
       return ssh_userauth_autopubkey(sshSession);
    */
}
