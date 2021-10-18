/// Homework 4: Guess the problem
/*
● What are the problems in this code?
● Why?
● How may we solve it (syntax)?
*/

/// Access Specifier

#include<iostream>
using namespace std;

class A
{
protected:
    int px;
    void pf()
    {

    }
};

class B
{
protected:
    int px;
    void pf()
    {

    }
    int GetSalary()
    {
        return 100;
    }
};

class C: public A, public B
{
public:
    void f()
    {
        // If common data/function, use resolution operator to specify which one as compiler will be confused (Ambiguity)
        A::px = 1; // to access px from A
        B::pf();  // to access pf from B
    }
    int GetSalary()
    {
        // The developer wanted to call parent GetSalary, but his method is same name
		// This will be infinite recursion. Again access parent clearly by B::
        int parent_salary = B::GetSalary();
        return 2 * parent_salary;
    }
};


int main()
{
    C cc;
    cout << cc.GetSalary();
    return 0;
}
