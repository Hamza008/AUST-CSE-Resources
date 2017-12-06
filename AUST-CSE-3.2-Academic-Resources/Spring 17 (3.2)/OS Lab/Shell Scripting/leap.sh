#!/bin/bash

echo "How many times do you want this program to run?"

read x

for (( i = 1 ; i <= x; i++))
do
echo "Iteration number $i:"
echo
echo
echo "Enter a year to check"

read a

c=$(( $a % 400))
b=$(( $a % 4))
d=$(( $a % 100))

if [ $c -eq 0 ]
then
  echo "$a is a leap"
elif [ $b -eq 0 ] && [ $d -ne 0 ]
then
  echo "$a is a leap"
else
  echo "$a is not a leap"
fi
done

