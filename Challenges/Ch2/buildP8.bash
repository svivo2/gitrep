#!/bin/bash
set -u -e
echo "Building..."
g++ -Wall P8.cpp -o p8
echo "Running..."
./p8
