#include "gtest/gtest.h"
#include<iostream>
#include<string>

#include<boost/algorithm/string.hpp>

std::string::size_type onlyEnds_with(const std::string& str, const std::string& subStr)
{
    std::string::size_type n = str.find(subStr);

    if (n != std::string::npos && str.substr(n).size() == subStr.size())
    {
        return n;
    }

    return std::string::npos;
}

TEST(String, onlyEnds_with)
{
    /*ends_with*/
    EXPECT_EQ(onlyEnds_with("123456", "56"), 4);
    EXPECT_EQ(onlyEnds_with("12563456", "56"), std::string::npos);

    /*not ends_with*/
    EXPECT_EQ(onlyEnds_with("123456", "34"), std::string::npos);
    EXPECT_EQ(onlyEnds_with("123456", "78"), std::string::npos);
}

TEST(String, char2String)
{
    const char* chr = "12345\0hj";
    EXPECT_EQ(strlen(chr), 5);

    std::string str(chr);
    EXPECT_EQ(str.size(), 5);

    std::string str1(chr, 8);
    EXPECT_EQ(str1.size(), 8);
}

TEST(String, std_copy_n)
{
    char* chr = new char[9];
    char chr1[] = { '2', '3', '4', '5', '6', '7', '8', '9', '\0'};
    std::cout << chr1 << std::endl;

    std::copy_n(chr1, 9, chr);
    std::cout << chr << std::endl;

    delete []chr;
}

TEST(String, std_copy_n_INT)
{
    long interfaceId = 345;
    unsigned char addr[8];

    std::copy_n((char*)&interfaceId, sizeof(long), addr);
    std::cout << *(long*)addr << std::endl;
}

TEST(String, substr)
{
    std::string str("123456789");//9

    std::string::size_type n = str.find("789");//6
    std::cout << n << std::endl;

    std::string substr = str.substr(n + 3);
    std::cout << substr << std::endl;

}

TEST(String, strtok_r)
{
    char str[] = "    123 456";

    char *tmp;
    char *ptr = strtok_r(str, " ", &tmp);
    EXPECT_EQ(std::string(ptr), "123");
}

TEST(String, ignoreEquals)
{
    std::string str1("aBc");
    std::string str2("Abc");

    EXPECT_EQ(boost::iequals(str1, str2), true);
}

TEST(String, ignoreStarts)
{
    std::string str1("aBcdfgb");
    std::string str2("Abc");

    EXPECT_EQ(boost::istarts_with(str1, str2), true);
}
