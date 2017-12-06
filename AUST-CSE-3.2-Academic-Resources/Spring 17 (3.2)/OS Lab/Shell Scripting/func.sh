#!/bin/bash

add()
{
  c=$(( $1 + $2 ))	
  echo "summation is $c"
}

echo "Enter two digits"
read a b
add a b
