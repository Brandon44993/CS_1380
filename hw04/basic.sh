#!/bin/bash

first_number=10
second_number=5
global_number=10

sum=$((first_number + second_number))
total=$((sum + global_number))

echo "First number: $first_number"
echo "Second number: $second_number"
echo "Sum: $sum"
echo "Global number: $global_number"
echo "Total using local and global variables: $total"
