#!/bin/bash
# Build all C/C++ programs in the current folder
# Makhtar Diouf
clear

for i in *.cpp *.c  ; 
    do echo; 
    # Tweak terminal colors
       # echo -en '\E[38;33m'"\033[1m";
    if [[ -e "Makefile" ]]
    then
	make -s -f Makefile $* `echo $i | cut -f1 -d'.' `
    else
	make -s -f ../Makefile $* `echo $i | cut -f1 -d'.' `
    fi
done

# Reset colors
tput sgr0
echo "Binaries: "
ls build/
exit
