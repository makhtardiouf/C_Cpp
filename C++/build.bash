#!/bin/bash
# Build all C/C++ programs in this folder
clear
# Red colors
echo -en "\033[1m"

for i in *.cpp *.c  ; 
    do make -s `echo $i | cut -f1 -d'.' ` ; 
done

echo -en '\E[47;31m'"\033[1mBinaries: "
ls build/
echo  -en "\033[0m"
# Reset colors
tput sgr0
exit
