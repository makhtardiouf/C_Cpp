#!/bin/bash
# Build all C/C++ programs in this folder
clear

for i in *.cpp *.c  ; 
    do echo; 
    # Tweak terminal colors
    # echo -en '\E[38;33m'"\033[1m";
    make -s $* `echo $i | cut -f1 -d'.' ` ; 
done

# Reset colors
tput sgr0
echo "Binaries: "
ls build/
exit
