#!/bin/bash

# get gtest 
git clone git@github.com:google/googletest.git

# cp gtest include
cp googletest/googletest/include/ include/ -rf

# build static library
cd googletest/googletest/
mkdir buildout
cd buildout
cmake ../
make 
cp lib/ ../../../lib/ -rf

# build dynamic library

