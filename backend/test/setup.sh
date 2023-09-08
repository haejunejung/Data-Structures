#!/bin/bash

# install googletest
echo "INSTALL GOOGLETEST"
mkdir gtest_build
cd gtest_build || exit
git clone https://github.com/google/googletest
cd ./googletest || exit
mkdir build
cd ./build || exit
cmake ..
make
make install


exit 0