#include "gtest/gtest.h"

#include <string>
#include <iostream>

using namespace std;

TEST(smartUsage, comma)
{
    ASSERT_EQ(24, (3 * 5, 4 * 6));

    int a = 0;
    ASSERT_EQ(60, (a = 3 * 5, a * 4));

    a = 0;
    ASSERT_EQ(0, (a = (3 * 5, a * 4)));
}

class Base
{
public:
    Base() = default;
    virtual ~Base() = default;

    void set(const int& a)          { _a = a; }
    int  getA() const               { return _a; }

    void set(const float& b)        { _b = b; }
    float getB() const              { return _b; }

    void set(const bool& c)         { _c = c; }
    bool getC() const               { return _c;}

    void set(const string& d)       { _d = d; }
    string getD() const             { return _d; }

    void showAll() const
    {
        cout << "a: " << _a << endl
             << "b: " << _b << endl
             << "c: " << _c << endl
             << "d: " << _d << endl;
    }

private:
    int         _a;
    float       _b;
    bool        _c;
    string      _d;
};

// ArbitraryComma data1 {int, float, bool, string};
// ArbitraryComma data1 {int, bool, float};
class ArbitraryComma : public Base
{
public:
    template<typename ... Args>
    ArbitraryComma(Args&& ... args)
    {
        int dummy[] { (cout << "expansion: " << args << endl, set(forward<Args>(args)), 0) ... };
        (void)dummy;
    }
};

template<typename T>
void expansion(Base& b, T&& t)
{
    cout << "expansion: " << t << endl;
    b.set(forward<T>(t));
};

template<typename T, typename... Args>
void expansion(Base& b, T&& t, Args&&... args)
{
    cout << "expansion: " << t << endl;
    cout << "args... size is: " << sizeof...(args) << endl; 

    b.set(forward<T>(t));
    expansion(b, forward<Args>(args)...);
};

class ArbitraryRecursion : public Base
{
public:
    template<typename... Args>
    ArbitraryRecursion(Args&&... args)
    {
        expansion(*this, forward<Args>(args)...);        
    }
};

TEST(smartUsage, arbitraryComma)
{
    ArbitraryComma data1 {5, (float)6.5, string("data1"), false};
    data1.showAll();

    ArbitraryComma data2 ((float)5.8, true);
    data2.showAll();
}

TEST(smartUsage, arbitratyRecursion)
{
    ArbitraryRecursion data1(5, (float)4.3, false, string("data1"));
    data1.showAll();

    ArbitraryRecursion data2 {true, 5, string("data2")};
    data2.showAll();
}







