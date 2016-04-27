#!/bin/bash
# $Id: install.bash 8 2007-05-22 15:06:00Z makhtar $
# Install edimexch, edimexchsend, edimexchrcv

INSTALL_PATH=/usr/local/bin
RES_PATH=/usr/local/share/edimexch

function Install()
{
    su -c "install -vs -m 755 edimexch $INSTALL_PATH ;\
    mkdir -p $RES_PATH; install -v tr_edimexch_fr.qm $RES_PATH ;\
    install -v -m 644 ../docs/edimexch.1 /usr/local/man/man1"
}

{
    echo "Installing edimexch in $INSTALL_PATH..."
    sleep 1
    Install
    echo "Done"
} | tee install.log

exit
