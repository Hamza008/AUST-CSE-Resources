#!/bin/bash

echo "Enter two numbers"
read num1
read num2
c=$((num1+num2))
echo "Summation is :" $c 
if [ $num1 -gt $num2 ]
then
  echo "num1 is greater"
else 
  echo "num2 is greater"
fi
