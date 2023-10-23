#!/bin/bash

set -e

# cd up one directory
cd ..

# cd into the src
cd src

# build project
echo "building project"
cmake --build build

# run project
echo "running project in debug"
cd build && ctest