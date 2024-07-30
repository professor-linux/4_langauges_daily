#!/bin/bash

filename=$1
text=$2


if  ! [ -f $filename ]; then
	echo "File does not exist ... Creating file.";
        touch $filename;
	echo $text > $filename;
else 
       read -p "File Exists, would you like to overwrite[y], or Append[a] or Quit [q]" answer
       case "$answer" in
	       y|Y)
		       echo "You chose to overwrite file";
		       echo $text > $filename;
		       ;;
	       a|A)    echo "You chose to Append file";
		       echo $text >> $filename;
	               ;;
               q|Q)  
		       echo "quitting now.."
		       
		       ;;
	       *)
		       echo "Invalid option"
		       exit 1;
		       ;;
       esac


fi

