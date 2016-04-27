#!/bin/bash
# $Id: beautify.bash 8 2007-05-22 15:06:00Z makhtar $
# Indent source files and generate tag files
BASE_FILES=`ls base/*.{cpp,h,hpp}`
GUI_FILES=`ls gui/*.{cpp,hpp}`

astyle  $BASE_FILES $GUI_FILES
ebrowse $BASE_FILES $GUI_FILES
etags $BASE_FILES $GUI_FILES
exit
