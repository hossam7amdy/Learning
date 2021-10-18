///Homework 6: Decorated String
/*
● In C++, we can use array of chars to represent strings: char foo [20];
● The str string class is a very powerful class to handle strings
    ○ Several constructors, operators and more functionalities
● There is a need for a class that has all features of string class, but
    ○ We need one extra functionality: method decorate
    ○ If called, it convert some str to <<[[str]]>>
*/

#include<iostream>
#include<string>
using namespace std;

class DecorationgString: public string
{
private:
    using string::string;
public:

    // using std::string::operator=;
    void decorate()
    {
        string s = *this;
        s = "<<[[" + s + "]]>>";

        //*this = s;
        this->assign(s);

        // You can't just use: *this = str;
		// as this is = assignment operator (later to study)
		// The default assignment operator = now is for DecoratedString not std::string
		// If you want it possible, add also using std::string::operator=;
    }
};

int main()
{
    DecorationgString str("I am learning CS");

    str.decorate();
    cout << str << endl;
    cout << (str == "<<[[I am learning CS]]>>");
    return 0;
}
