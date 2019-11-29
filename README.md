# Get googletest
git clone git@github.com:google/googletest.git

# Googletest static library


# Googletest dynamic library


# C-FuzzyKnowledge
some c++ fuzzy knowledge, use googleTest to show it

# Need googletest static library

g++ src/test.cpp -I./include -L./lib -lgtest -lpthread -o test.o
