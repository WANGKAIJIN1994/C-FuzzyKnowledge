#include "gtest/gtest.h"

#include <iostream>
#include <string>

using namespace std;

class LearnConstructor
{
public:
    explicit LearnConstructor(const string& s)
    {
        _test = s;
        cout << "constructor " << _test << endl;
    }

    /*explicit*/ LearnConstructor(LearnConstructor& s)
    {
        _test = s.getTest();
        cout << "copy constructor " << _test << endl;
    }

    /*explicit*/ LearnConstructor(const LearnConstructor& s)
    {
        _test = s.getTest();
        cout << "const copy constructor " << _test << endl;
    }

    explicit LearnConstructor(LearnConstructor&& s)
    {
        _test = move(s.getTest());
        cout << "move constructor " << _test << endl;
    }

    LearnConstructor& operator=(LearnConstructor& s)
    {
        _test = s.getTest();
        cout << "assign constructor " << _test << endl;
        return *this;
    }

    LearnConstructor& operator=(const LearnConstructor& s)
    {
        _test = s.getTest();
        cout << "move constructor " << _test << endl;
        return *this;
    }

    string getTest() const
    {
        return _test;
    }

private:
    string _test;
};

TEST(LearnConstruct, move)
{
    cout << "*******l1*********" << endl;
    LearnConstructor l1("l1");

    cout << "*******l2*********" << endl;
    const LearnConstructor l2("l2");

    cout << "*******l3*********" << endl;
    LearnConstructor l3(l1);

    cout << "*******l4*********" << endl;
    LearnConstructor l4(l2);

    cout << "*******l5*********" << endl;
    LearnConstructor l5 = l1;

    cout << "*******l6*********" << endl;
    LearnConstructor l6 = l2;

    cout << "*******l7*********" << endl;
    LearnConstructor l7(move(l1));

    cout << "*******l8*********" << endl;
    LearnConstructor l8(move(l2));

    cout << "*******l9*********" << endl;
        l4 = l3;
}
