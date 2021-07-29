#include <iostream>
using namespace std;

/*
● Read a string, then divide it to consecutive groups of same letter. Print each
group
● Input ⇒ outputs.
    ○ “111222aabbb” ⇒ 111 222 aa bbb
    ○ HHHH ⇒ HHHH

*/

int main(){
    string str;
    cin >> str;

    //Dr's did it in a very easy way think deeper and stop brute-forcing.

    string grouped = "";
    grouped += str[0];
    int sz = str.size();
    for(int i=1; i<sz; i++){
        if(str[i-1]==str[i])
            grouped+=str[i];
        else{
            grouped+=" ";
            grouped+=str[i];
        }
    }

    cout << grouped;





    return 0;
}
