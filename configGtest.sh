#!/bin/bash

# create include & lib
mkdir include
mkdir lib

# get gtest 
git clone git@github.com:google/googletest.git

# cp gtest include
cp googletest/googletest/include/gtest/ include/ -rf

# create buildout file
cd googletest/googletest/
mkdir buildout
cd buildout

# build static library
#rm * -rf
#cmake ../
#make 
#cp lib/libgtest* ../../../lib/ -rf

# build dynamic library
rm * -rf
cmake -DBUILD_SHARED_LIBS=ON ../
make
cp lib/libgtest* ../../../lib/ -rf

# clear 
cd ../../../
rm googletest -rf

