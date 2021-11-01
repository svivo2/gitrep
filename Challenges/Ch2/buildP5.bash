#!/bin/bash
set -u -e
echo "Building..."
g++ -Wall P5.cpp -o p5
echo "Running..."
./p5
