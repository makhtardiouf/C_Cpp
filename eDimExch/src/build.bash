#!/bin/bash
# $Id: build.bash 8 2007-05-22 15:06:00Z makhtar $
# Build edimexch


# MAINOPTS="-ansi -ggdb -funsigned-char -O2 -finline-functions -freorder-functions\
#  -static -fpic -fbounds-check -Wformat -Wextra -Wshadow -Wredundant-decls"
MAINOPTS="-ansi -ggdb -funsigned-char -finline-functions -freorder-functions\
 -fpic -fbounds-check -Wformat -Wextra -Wshadow -Wredundant-decls"


function ConfigProject()
{
    PROJ_NAME=$1

    if [ ! -z $2 ]; then
	CONF_COMPL="$2"
    else
	CONF_COMPL=""
    fi

    qmake -project -o $PROJ_NAME.pro -norecursive -Wall ../base \
        "CONFIG += qt debug exceptions warn_on " "QT += network "\
	"QMAKE_CFLAGS_DEBUG += $MAINOPTS -pedantic -Wbad-function-cast \
        -Wold-style-definition -Wmissing-declarations -Wno-pointer-sign "\
	"QMAKE_CXXFLAGS_DEBUG += $MAINOPTS " "LIBS += -lssh -lssl -lz -lssh "\
        "TARGET = $PROJ_NAME " "MOC_DIR = .tmp " "OBJECTS_DIR = .tmp "
}


function Build()
{
    qmake
    make clean
    make

    if [ $? -ne 0 ]; then
	echo "Build failed";
	exit $?
    fi
}

function BuildGui()
{
    cd gui
    printf "\n\n*** Building edimexchgui...\n\n"
    ConfigProject edimexchgui
    Build
    cd -
}

function BuildDocs()
{
    printf "\nGenerating documentation...\n"

}


{
    clear

#    if [ "$1" == "1" ] ; then
	BuildGui
#    else

#    lupdate -noobsolete qirda.pro
#    lrelease qirda.pro
#    make

#    cd ../docs
#    BuildDocs
#    cd -

    printf "\n\n\tFinished Building. You can run ./install.bash now\n\n"

} | tee build.log

exit $?
