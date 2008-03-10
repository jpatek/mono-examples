#!/bin/bash

if [ $# -lt 2 ]
then
	echo
	echo "Usage $(basename $0) <directory_to_clone> <name_of_clone>"
	echo
	exit 5
fi

function check_dirs()
{
	SRCDIR=$1
	DSTDIR=$2
	
	if [ ! -d $SRCDIR ]
	then
		echo
		echo "Error: $SRCDIR doesn't exist"
		echo
		exit 5
	fi

	if [ -d $DSTDIR ]
	then
		echo
		echo "Error: $SRCDIR exists"
		echo
		exit 5
	fi
}

function clone_dir()
{
	SRCDIR=$1
	SRCDIRNAME=$(basename $SRCDIR)
	DSTDIR=$2

	echo -n "Copying $SRCDIR to $DSTDIR... "
	cp -a -- $SRCDIR $DSTDIR && echo "Done." || exit 5

	cd $DSTDIR

	echo -n "Removing extraneous files from $DSTDIR dir... "
	rm -rf -- .svn .prec bin ChangeLog *.d *.o *.pidb && echo "Done." || exit 5

	echo -n "Fixing the $DSTDIR project file... "
	cat $SRCDIRNAME.mdp | sed -e "s/$SRCDIRNAME/$DSTDIR/g" > $DSTDIR.mdp && echo "Done." || exit 5
	rm -- $SRCDIRNAME.mdp

	cd ..
}

check_dirs $1-in_c  $2-in_c
check_dirs $1-in_cs $2-in_cs

clone_dir $1-in_c  $2-in_c
clone_dir $1-in_cs $2-in_cs

echo
echo "The script completed successfully."
