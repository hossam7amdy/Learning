#include<iostream>
using namespace std;
/*
● Read two strings S and T. Print a new string that contains the following:
    ○ First letter of the string S followed by the First letter of the string T.
    ○ Second letter of the string S followed by the Second letter of the string T.
    ○ and so on...
● Don’t create new strings. Don’t change input content
● Input ⇒ Output
    ○ abc defghi ⇒ adbecfghi
    ○ AM CICPC ⇒ ACMICPC
*/


int main() {
    string s,t;
    cin >> s >> t;
    int sz;
    if(s.size()>t.size())
        sz = s.size();
    else
        sz = t.size();

    for(int i=0; i<sz; i++){
        if(i<s.size())
            cout << s[i];
        if(i<t.size())
            cout << t[i];
    }


	return 0;
}
