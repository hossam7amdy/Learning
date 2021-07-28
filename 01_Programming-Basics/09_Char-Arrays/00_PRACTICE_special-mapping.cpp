#include<iostream>
using namespace std;
/*
● Read a string and do the following conversions for its letters
    ○ If it is an upper letter, don’t change
    ○ If it is lower letter, use this map of 26 letters:
■ abcdefghijklmnopqrstuvwxyz
■ YZIMNESTODUAPWXHQFBRJKCGVL
■ E.g. a ⇒ Y and z ⇒ L
    ○ If it is digit, use this map of 10 letters:
■ 0123456789
■ !@#$%^&*()
● Input ⇒ Output
    ○ acMNmn39 ⇒ YIMNPW$)
    ○ vwXYZ0123 ⇒ KCXYZ!@#$

*/


int main() {
    char mp[] {'Y','Z','I','M','N','E','S','T','O','D','U','A','P','W','X','H','Q','F','B','R','J','K','C','G','V','L'};
    char num[] {'!','@','#','$','%','^','&','*','(',')'};
    string str;
    cin >> str;
    for(int i = 0; i<=str.size(); i++){
        int idx;
        if(str[i]>=97){
            idx = str[i];
            str[i] = mp[idx-97];
        }

        if(48<=str[i] && str[i]<=57){
            idx = str[i] - 48;
            str[i] = num[idx];
        }
    }

    cout << str;


	return 0;
}
