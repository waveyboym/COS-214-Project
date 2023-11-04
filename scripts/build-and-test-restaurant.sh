# set up build files
echo "setting up build in debug type"
cmake -DCMAKE_BUILD_TYPE=Debug -S . -B build

# build project
echo "building project"
cmake --build build

# run project
echo "running project"
cd build && ctest -V