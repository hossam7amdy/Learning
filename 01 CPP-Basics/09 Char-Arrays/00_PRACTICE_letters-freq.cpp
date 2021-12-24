#include<iostream>
using namespace std;
/*
● Read a string of lower/upper letters. Ignore upper letters and compute the
frequency of lower letters. Print ones that exists as below.
● Input: bAAAaaazz
● Output
    ○ a 3
    ○ b 1
    ○ z 2
*/


int main() {
    int freq[200]={0};
    string str;
    cin >> str;
    int sz = str.size();
    for(int i=0; i<sz; i++){
        if(str[i]>=97)
            freq[str[i]]++;
    }

    for(int i=0; i<200; i++){
        if(freq[i])
            cout << char(i) << " = " << freq[i] << '\n';
    }


	return 0;
}
