#!/bin/bash
#Created by Leonardo Fusser (1946995)

my_array=(4 56 78 90 23)			#array with some values

echo "[Start of script!]"
echo

#(Checks number of arguments passed)
if [ $# != 1 ]; then				#1 argument needed
 echo "Enter a value greater 1!"
 echo
 echo "[End of script!]"
 exit 2

fi

#(Loop to print number of array elements based on argument)
for (( i = 0; i < $1; i++ ));
do
	echo "${my_array[$i]}";
done

echo
echo "[End of script!]"
