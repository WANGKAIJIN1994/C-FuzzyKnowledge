#include "gtest/gtest.h"

#include <iostream>
#include <string>

using namespace std;

class LearnConstructor
{
public:
    LearnConstructor()
    {
        cout << "no args constructor" << endl;
    }

    explicit LearnConstructor(const string& s)
    {
        _test = s;
        cout << "constructor " << _test << endl;
    }

    LearnConstructor(LearnConstructor& s)
    {
        _test = s.getTest();
        cout << "copy constructor " << _test << endl;
    }

    LearnConstructor(const LearnConstructor& s)
    {
        _test = s.getTest();
        cout << "const copy constructor " << _test << endl;
    }

    explicit LearnConstructor(/*const*/ LearnConstructor&& s)
    {
        _test = move(s.getTest());
        cout << "move constructor " << _test << endl;
    }

    LearnConstructor& operator=(LearnConstructor& s)
    {
        _test = s.getTest();
        cout << "assign " << _test << endl;
        return *this;
    }

    LearnConstructor& operator=(/*const*/ LearnConstructor&& s)
    {
        _test = move(s.getTest());
        cout << " move assign " << _test << endl;
        return *this;
    }

    string getTest() const
    {
        return _test;
    }

    virtual LearnConstructor& show()
    {
        cout << "show " << _test << endl;
        return *this;
    }

    virtual ~LearnConstructor() = default;

private:
    string _test;
};


class Derived : public LearnConstructor
{
public:
    explicit Derived(const std::string& s) : LearnConstructor(s)
    {
        cout << "Derived constructor" << endl;
    }

    Derived& show() override
    {
        cout << "Derived show " << this->getTest() << endl;
        return *this;
    }
};

class TestArgs
{
public:
    int number1;
    int number2;
    LearnConstructor learnConstructor;

    TestArgs(int number, LearnConstructor learnConstructor) : number2(number), number1(number2), learnConstructor(learnConstructor)
    {
        cout << "TestArgs::constructor number1:" << number1 << ", number2:" << number2 << endl;
    }

    TestArgs(LearnConstructor learnConstructor)
    {
        learnConstructor = learnConstructor;
        cout << "TestArgs::constructor" << endl;
    }
};

TEST(LearnConstruct, move)
{
    cout << "*******LearnConstructor l1(\"l1\")*********" << endl;
    LearnConstructor l1("l1");

    cout << "*******const LearnConstructor l2(\"l2\")*********" << endl;
    const LearnConstructor l2("l2");

    cout << "*******LearnConstructor l3(l1)*********" << endl;
    LearnConstructor l3(l1);

    cout << "*******LearnConstructor l4(l2)*********" << endl;
    LearnConstructor l4(l2);

    cout << "*******LearnConstructor l5 = l1*********" << endl;
    LearnConstructor l5 = l1;

    cout << "*******LearnConstructor l6 = l2*********" << endl;
    LearnConstructor l6 = l2;

    cout << "*******LearnConstructor l7(move(l1))*********" << endl;
    LearnConstructor l7(move(l1));

    cout << "*******LearnConstructor l8(move(l2)),(call const LearnConstructor&& s, if exist)*********" << endl;
    LearnConstructor l8(move(l2));

    cout << "*******l4 = l3*********" << endl;
    l4 = l3;

    cout << "*******l4 = move(l3)*********" << endl;
    l4 = move(l3);
}

TEST(Derived, override)
{
    LearnConstructor l1("LearnConstructor");
    Derived d1("Derived");

    LearnConstructor& base1(l1);
    LearnConstructor& base2(d1);

    base1.show();
    base2.show();
}

TEST(LearnConstruct, TestArgs)
{
    LearnConstructor l0;

    cout << "********begin test Parameter initialization list******" << endl;
    TestArgs test(10, l0);

    cout << "********begin test assign******" << endl;
    TestArgs test1(l0);
}
