#!/bin/bash

for i in $(seq 1 $1)
do
    if (( i % 15 == 0 ))
    then
        echo "FizzBuzz"
    elif (( i % 3 == 0 ))
    then
        echo "Fizz"
    elif (( i % 5 == 0 ))
    then
        echo "Buzz"
    else
        echo "$i"
    fi
done