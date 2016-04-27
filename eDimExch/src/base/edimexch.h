/*****************************************************************
 * $Id: edimexch.h, ca5aafa57b53  makhtar $
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

/** Application wide utilities */
#ifndef EDIMEXCH_H
#define EDIMEXCH_H
#include "edimutils.h"

#define APP_NAME  "eDimExch"
#define APP_VERSION  "0.1a " __DATE__
#define APP_DEFINITION  "Dimorphic data Exchanger"
#define AUTHOR "Makhtar Diouf \n<elmakdi@users.sourceforge.net>"

#ifndef __WIN32__
# include <libssh/libssh.h>
# include <libssh/sftp.h>

/*
#include <libssh2.h>
#include <libssh2_sftp.h>
#include <libssh2_publickey.h>
*/

/* # include <gpgme.h> */
#else
/*
# include "libssh/libssh.h"
# include "libssh/sftp.h"
*/
#endif
#endif
