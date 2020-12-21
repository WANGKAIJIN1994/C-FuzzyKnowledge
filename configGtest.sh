#!/bin/bash

# create include & lib
mkdir include
mkdir lib

# get gtest 
git clone https://github.com/google/googletest.git
cd googletest

# build static library
#cmake -DCMAKE_INSTALL_PREFIX=./lib  ./
#make 
#make install

# build dynamic library
cmake -DBUILD_SHARED_LIBS=ON -DCMAKE_INSTALL_PREFIX=./lib  ./
make
make install

# move include&lib to CPlusPlusKnowledge
cp lib/include/* ../include/ -rf
cp lib/libg* ../lib/ -rf 

# clear 
cd ../
rm googletest -rf
