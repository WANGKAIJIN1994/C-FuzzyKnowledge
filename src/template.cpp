#include "gtest/gtest.h"

#include <iostream>
#include <string>

void print(int n)
{
    std::cout << "int" << n << std::endl;
}

void print(double d)
{
    std::cout << "double" << d << std::endl;
}

void print(std::string s)
{
    std::cout << "string" << s << std::endl;
}

template<typename T, typename... Args>
void print(T t1, Args... args)
{
    print(t1);
    print(args...);
}

TEST(Template, 1)
{
    print(1,2,3.4,5,std::string("sf"),6);
}
