#!/bin/bash --debugger
# $Id: commit.bash 8 2007-05-22 15:06:00Z makhtar $
# Commit changes of eDimExch related files
EDIM_ROOT_PATH=$HOME/Documents/Dev/DevEmd/Cteam/eDimExch/trunk
EDIM_SRC_DIR=$EDIM_ROOT_PATH/src
EDIM_DOCS_DIR=$EDIM_ROOT_PATH/docs
COMMENTS=$EDIM_DOCS_DIR/commitmsg.txt

{
    for i in $EDIM_DOCS_DIR/*.* $EDIM_SRC_DIR/{base,gui}/*.{cpp,h,hpp}
      do
      SetId.bash $i
    done

    bash $EDIM_SRC_DIR/beautify.bash

    cd $EDIM_ROOT_PATH

    if [ "$1" == "++" ]; then
	svn commit -m "++"
    elif [ "$1" == "txt" ]; then
	echo "Using \"$COMMENTS\" as commit documentation..."
	svn commit -F $COMMENTS
    else
	echo "Usage: `basename $0` ++ OR `basename $0` txt"
    fi
} | tee commit.log

exit
