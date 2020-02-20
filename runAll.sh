#!/bin/bash

# Delete objective files and former output files
echo "-------REMOVE USELESS FILES------"
make clean
rm -f ./datasets/*.out

# Compile program
echo "---------COMPILE PROGRAM---------"
make

# Run all input datasets
echo "---------RUN ALL DATASETS--------"
./hashcode_solution -i ./datasets/a_example.in
echo "---------------------------------"
./hashcode_solution -i ./datasets/b_small.in
echo "---------------------------------"
./hashcode_solution -i ./datasets/c_medium.in
echo "---------------------------------"
./hashcode_solution -i ./datasets/d_quite_big.in
echo "---------------------------------"
./hashcode_solution -i ./datasets/e_also_big.in
