#!/bin/bash
set -u -e
echo "Building..."
javac CarTest.java
echo "Running..."
java CarTest
