/*****************************************************************
 * $Id: GuiSftp.cpp 7 2007-05-22 15:03:42Z makhtar $
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

#include "GuiSftp.hpp"
#include <iostream>


AbstractSftp::AbstractSftp(QWidget *papa)
        : QWidget(papa)
{
    setBackgroundRole(QPalette::Window);

    QSpacerItem* firstSpacer = new QSpacerItem(10, 10);

    QLabel* hostLabel = new QLabel("[user@]host");

    host = new QLineEdit();
    host->setToolTip("Enter a hostname or IP address");
    host->setMinimumWidth((this->width()/3) + 10);

    detailsBt = new QPushButton("D&etails...");
    detailsBt->setEnabled(false);

    //temp
    detailsWin = new AbstractDetailsWin(papa);
    detailsWin->setHidden(true);
    detailsWin->setWindowTitle(APP_NAME" Connecting...");

    QLabel* localfsLabel = new QLabel("Local Filesystem");

    localPath = new QComboBox();
    localPath->setMaximumHeight(25);
    localPath->setEditable(true);
    localPath->setInsertPolicy(QComboBox::InsertAtTop);
    localPath->insertItem(0, QDir::homePath());
    localPath->setAutoCompletion(true);

    cdUpLocBt = new QPushButton("Up");
    cdUpLocBt->setMaximumHeight(25);
    cdUpLocBt->setMaximumWidth(30);

    localfsModel = new QDirModel();
    localfsModel->setReadOnly(true);
    localfsModel->setIconProvider(new QFileIconProvider());
    localfsModel->setSorting(QDir::DirsFirst);

    localfs = new QTreeView();
    localfs->setModel(localfsModel);
    localfs->setRootIndex(localfsModel->index(QDir::homePath()));
    //     localfs->setContextMenuPolicy(Qt::CustomContextMenu);
    //     localfs->setMouseTracking(true);
    localfs->setToolTip("Local Filesystem");

    uploadBt = new QPushButton("  &Upload  >> ");
    uploadBt->setToolTip("Upload file(s) to remote host");
    uploadBt->setEnabled(false);

    uploadBt->setSizePolicy(QSizePolicy::Fixed,
                            QSizePolicy::Fixed);

    QSpacerItem* spacerItem2 = new QSpacerItem(30, 30);

    downloadBt = new QPushButton("<< &Download");
    downloadBt->setToolTip("Download file(s) to local host");
    downloadBt->setEnabled(false);
    downloadBt->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    jobsModel = new QStandardItemModel(3, 2);
    jobsModel->setHeaderData(0, Qt::Horizontal, "File");
    jobsModel->setHeaderData(1, Qt::Horizontal, "Progress");
    //     jobsModel->setHeaderData(2, Qt::Horizontal, "Speed");

    jobs = new QTableView();
    jobs->setModel(jobsModel);
    jobs->setShowGrid(false);
    jobs->setGridStyle(Qt::NoPen);
    jobs->setToolTip("Current transfers");
    jobs->setMinimumWidth(200);
    jobs->setMinimumHeight(100);
    jobs->setMaximumWidth(150);
    jobs->setSizePolicy(QSizePolicy::Expanding,
                        QSizePolicy::Expanding);

    QLabel* remotefsLabel = new QLabel("Remote Filesystem");
    //remotefsLabel->setFont(boldelize);
    remotefsLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    remotePath = new QComboBox();
    remotePath->setMaximumHeight(25);
    remotePath->setEditable(true);

    cdUpRemBt = new QPushButton("Up");
    cdUpRemBt->setMaximumHeight(25);
    cdUpRemBt->setMaximumWidth(30);

    remotefs = new QListWidget();
    //remotefs->setMouseTracking(true);
    remotefs->setToolTip("Remote Filesystem");
    remotefs->setResizeMode(QListView::Adjust);

    // Setup the layouts
    QHBoxLayout* inputLayout = new QHBoxLayout();
    inputLayout->setSpacing(8);
    inputLayout->setMargin(10);
    inputLayout->insertStretch(0);
    inputLayout->addWidget(hostLabel);
    inputLayout->addWidget(host);
    inputLayout->addWidget(detailsBt);

    // Insert Strechable space at the end of horizontal layout
    inputLayout->insertStretch(-1);

    QVBoxLayout* loadBtsLayout = new QVBoxLayout();
    loadBtsLayout->setMargin(25);
    loadBtsLayout->addWidget(uploadBt, Qt::AlignHCenter);
    loadBtsLayout->addItem(spacerItem2);
    loadBtsLayout->addWidget(downloadBt, Qt::AlignHCenter);

    QHBoxLayout* localNavLayout = new QHBoxLayout();
    localNavLayout->addWidget(localPath);
    localNavLayout->addWidget(cdUpLocBt);

    QHBoxLayout* remoteNavLayout = new QHBoxLayout();
    remoteNavLayout->addWidget(remotePath);
    remoteNavLayout->addWidget(cdUpRemBt);

    QGridLayout* centrLayout = new QGridLayout();
    centrLayout->setColumnStretch(1, 0);
    // centrLayout->setSpacing(5);
    centrLayout->setMargin(1);
    centrLayout->blockSignals(false);

    centrLayout->addWidget(localfsLabel, 0, 0, 1, 1);
    centrLayout->addLayout(localNavLayout, 1, 0, 1, 1);
    centrLayout->addWidget(localfs, 2, 0, 3, 1);

    centrLayout->addLayout(loadBtsLayout, 2, 1, 1, 1,
                           Qt::AlignHCenter);
    centrLayout->addWidget(jobs, 3, 1, 1, 1);

    centrLayout->addWidget(remotefsLabel, 0, 2, 1, 1);
    centrLayout->addLayout(remoteNavLayout, 1, 2, 1, 1);
    centrLayout->addWidget(remotefs, 2, 2, 3, 1);

    QGridLayout* AbstractSftpLayout = new QGridLayout();
    AbstractSftpLayout->setSpacing(5);
    AbstractSftpLayout->setMargin(0);
    AbstractSftpLayout->addItem(firstSpacer, 0, 0);
    AbstractSftpLayout->addLayout(inputLayout, 1, 0);
    AbstractSftpLayout->addLayout(centrLayout, 2, 0);
    setLayout(AbstractSftpLayout);

    contextMenu = new QMenu();
    uploadFile = new QAction("&Upload File", contextMenu);
    downloadFile = new QAction("&Download File", contextMenu);
    encryptFile = new QAction("En&crypt File", contextMenu);
    decryptFile = new QAction("Dec&rypt File", contextMenu);

    contextMenu->addAction(uploadFile);
    contextMenu->addAction(downloadFile);
    contextMenu->addAction(encryptFile);
    contextMenu->addAction(decryptFile);

    //dblClickSpy = new QSignalSpy(localfs, SIGNAL(itemDoubleClicked(QListWidgetItem*)));
    //selectionSpy = new QSignalSpy(localfs, SIGNAL(itemSelectionChanged()));

    QObject::connect(host, SIGNAL(returnPressed()), detailsWin, SLOT(exec()));

    QObject::connect(detailsBt, SIGNAL(clicked()), detailsWin, SLOT(exec()));

    QObject::connect(host, SIGNAL(textChanged(const QString&)),
                     SLOT(EnableDetailsBt()));

    //QObject::connect(localfs, SIGNAL(customContextMenuRequested(const QPoint&)),
    // contextMenu, SLOT(exec(QCursor::pos())));

    //QObject::connect(cdUpLocBt, SIGNAL(clicked()), SLOT(CdUpLocal()));
}


void
AbstractSftp::UpdateLocalFs(QListWidgetItem* item)
{
    std::cout<< "got dbl click at: " << item->text().toStdString() << "\n";
}

void
AbstractSftp::UpdateLocalFs()
{
    // int newTarget = dblClickSpy->count();
    // std::cout<< "dbl clicks: " << newTarget << "\n";
    // localfsDir->cd(QDir::currentPath().append("/").append(item->text()));
}

void
AbstractSftp::ListLocalFiles()
{
    //     QStringList files = localfsDir->entryList();
    //     localfs->clear();
    //     localfs->addItems(files);
}

void
AbstractSftp::EnableDetailsBt()
{
    QString url = host->text();
    if (!url.isEmpty())
        detailsBt->setEnabled(true);
}



AbstractDetailsWin::AbstractDetailsWin(QWidget *papa)
        : QDialog(papa)
{
    QLabel* portLabel = new QLabel("Port Number");
    port = new QSpinBox();
    port->setValue(22);
    port->setMinimum(-1);
    port->setMaximum(65535);

    QLabel* userLabel = new QLabel("Username");
    user = new QLineEdit();
    QLabel* passwLabel = new QLabel("Password");
    passw = new QLineEdit();
    passw->setEchoMode(QLineEdit::Password);
    QLabel* keyFileLabel = new QLabel("Public Key");
    keyFile = new QComboBox();
    keyFile->setMinimumWidth(100);
    keyFile->setEditable(true);

    QPushButton* keyBt = new QPushButton("Select...");
    keyBt->setSizePolicy(QSizePolicy::Fixed,
                         QSizePolicy::Fixed);

    QHBoxLayout* keyFileHL = new QHBoxLayout();
    keyFileHL->addWidget(keyFile);
    keyFileHL->addWidget(keyBt);

    connectBt = new QPushButton("C&onnect");
    connectBt->setSizePolicy(QSizePolicy::Fixed,
                             QSizePolicy::Fixed);

    cancelBt = new QPushButton("C&ancel");
    cancelBt->setSizePolicy(QSizePolicy::Fixed,
                            QSizePolicy::Fixed);

    QHBoxLayout* conCanHL = new QHBoxLayout();
    conCanHL->addWidget(connectBt);
    conCanHL->addWidget(cancelBt);

    QGridLayout* mainLay = new QGridLayout();
    mainLay->addWidget(portLabel, 0, 0);
    mainLay->addWidget(port, 0, 1);
    mainLay->addWidget(userLabel, 1, 0);
    mainLay->addWidget(user, 1, 1);
    mainLay->addWidget(passwLabel, 2, 0);
    mainLay->addWidget(passw, 2, 1);
    mainLay->addWidget(keyFileLabel, 3, 0);
    mainLay->addLayout(keyFileHL, 3, 1);

    QLabel* authMethLabel = new QLabel("Select an authentication method");

    passMeth = new QCheckBox("Password");
    passMeth->setCheckState(Qt::Checked);

    kbdIntMeth = new QCheckBox("Keyboard Interactive");
    kbdIntMeth->setCheckState(Qt::Unchecked);

    pubKeyMeth = new QCheckBox("Public Key");
    pubKeyMeth->setCheckState(Qt::Unchecked);

    QVBoxLayout* authentVL = new QVBoxLayout();
    authentVL->setMargin(10);
    authentVL->addLayout(mainLay);
    authentVL->addWidget(authMethLabel);
    authentVL->addWidget(passMeth);
    authentVL->addWidget(kbdIntMeth);
    authentVL->addWidget(pubKeyMeth);

    connBox = new QGroupBox("Connection Settings");
    connBox->setLayout(authentVL);

    QVBoxLayout* VLayoutit = new QVBoxLayout();
    VLayoutit->addWidget(connBox);
    VLayoutit->addLayout(conCanHL);

    setLayout(VLayoutit);
    setWindowTitle("Connection Settings");

    QFont w32Font = QFont();
    w32Font.setStyleHint(QFont::AnyStyle);
    w32Font.setStyle(QFont::StyleNormal);
    w32Font.setPointSize(13);
    setFont(w32Font);

    QObject::connect(connectBt, SIGNAL(clicked()), SLOT(accept()));

    QObject::connect(cancelBt, SIGNAL(clicked()), SLOT(reject()));

    QObject::connect(user, SIGNAL(returnPressed()), passw, SLOT(setFocus()));

    QObject::connect(passw, SIGNAL(returnPressed()),
                     this->connectBt, SIGNAL(clicked()));

    QObject::connect(keyBt, SIGNAL(clicked()), SLOT(SelectKey()));
}

void
AbstractDetailsWin::SelectKey()
{
    const QString pubKey = QFileDialog::getOpenFileName(this,
                           "Select Public Key",
                           QDir::homePath());

    if (!pubKey.isNull()) {
        keyFile->addItem(pubKey);
        this->show();
    }
}
