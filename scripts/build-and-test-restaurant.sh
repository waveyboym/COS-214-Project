#!/bin/bash
#if this script doesn't work, make sure it's set to LF mode

# cd up one directory
cd ..

# cd into the src
cd src

# set up build files
echo "setting up build in debug"
cmake -DCMAKE_BUILD_TYPE=Debug -S . -B build

# build project
echo "building project"
cmake --build build

# run project
echo "running project in debug"
cd build && ctest -V