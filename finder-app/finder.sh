#!/bin/sh

# exit with 1 if number of arguments is not 2
if [ $# -ne 2 ]
then
   echo "the script needs exactly 2 arguments"
   exit 1
fi

# exit with 1 if argument 1 is not a directory
if [ ! -d $1 ]
then
   echo "$1 directory does not exist"
fi

number_of_lines=$( grep -r $2 $1 | wc -l )
number_of_files=$( grep -rl $2 $1 | wc -l)

echo -n "The number of files are $number_of_files"
echo " and the number of matching lines are $number_of_lines"
