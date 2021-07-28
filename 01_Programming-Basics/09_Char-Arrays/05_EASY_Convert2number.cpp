#include <iostream>
using namespace std;

/*
● Read a string of 6 letters maximum, convert it to int then print
    ○ the number, the number multiplied by 3
● Input ⇒ output
    ○ “100” ⇒ 100 300
    ○ “0200” ⇒ 200 600
*/

int main(){
    string str;
    cin >> str;

    //instead of looking at ASCII Table use char '0' nice haa!
    int sz = str.size(), num=0;
    for(int i=0; i<sz; i++){
        num*=10;
        num += (str[i]-48);
    }

    cout << num << " " << num*3;


    return 0;
}
