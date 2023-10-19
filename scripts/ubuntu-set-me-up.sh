#!/bin/bash

set -e

echo "setting up for linux"

# download libgtest
echo "download libgtest"
sudo apt-get install libgtest-dev

# download cmake
echo "download cmake"
sudo apt-get install cmake

# download boost
echo "download boost"
sudo apt-get install libboost-all-dev

# install git
echo "download git"
sudo apt install git

# git clone the repo
echo "cloning repo"
git clone -b develop https://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@github.com/waveyboym/COS-214-Project.git

# cd into the project
cd COS-214-PROJECT/src

# set up build files
echo "setting up build"
cmake -DCMAKE_BUILD_TYPE=Release -S . -B build

# build project
echo "building project"
cmake --build build

# run project
echo "running project"
cd build && ./main