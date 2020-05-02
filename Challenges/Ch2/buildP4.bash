#!/bin/bash
set -u -e
echo "Building..."
g++ -Wall P4.cpp -o p4
echo "Running..."
./p4
