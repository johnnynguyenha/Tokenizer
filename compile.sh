#!/bin/bash

#Author: Johnny Nguyen
#Author email: johnnynguyenha@csu.fullerton.edu

#Program name: Tokenizer


echo "Remove old un-needed files, if any."
rm *.o
rm *.out

echo "Compile the C main function search.c according to C standard 2017"
gcc -c -Wall -m64 -no-pie -o array.o assignment3.c -std=c17 -lm

echo "Link object files"
gcc -m64 -no-pie -o assignment3.output array.o -lm

echo "Run the program \"String search\""
./assignment3.output

echo "The bash file has terminated."
