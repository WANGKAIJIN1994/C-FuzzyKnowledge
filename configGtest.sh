#!/bin/bash

# create include & lib
mkdir include
mkdir lib

# get gtest 
git clone https://github.com/google/googletest.git

# cp gtest include
#cp googletest/googletest/include/gtest/ include/ -rf

# create buildout file
cd googletest
#mkdir buildout
#cd buildout

# build static library
#rm * -rf
#cmake ../
#make 
#cp lib/libgtest* ../../../lib/ -rf

# build dynamic library
#rm * -rf

cmake -DBUILD_SHARED_LIBS=ON -DCMAKE_INSTALL_PREFIX=./lib  ./
make
make install
#cp lib/libgtest* ../../../lib/ -rf

# clear 
#cd ../../../
#rm googletest -rf

