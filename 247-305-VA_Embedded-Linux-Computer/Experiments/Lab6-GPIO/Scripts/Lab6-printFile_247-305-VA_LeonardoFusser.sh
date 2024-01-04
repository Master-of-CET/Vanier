#!/bin/bash
#Created by LeonardoFusser (1946995)

my_array=($(cat "./file.txt"))			#creates array from file.txt

echo "[Start of script!]"
echo

#(Loop for printing only first string without Line1 text)
for (( i = 1; i < 6; i++ ));
do
	echo -n ${my_array[i]} " "
done

#(Loop for addition operation)
for i in ${my_array[@]:1:6};
do
	sum=$((sum + i))			#performs addition operation
done

echo
echo "Sum: $sum"				#prints result of addition
echo
echo "[End of script!]"
