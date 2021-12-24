#include <iostream>
using namespace std;

/*
● Read 2 strings, then output YES if the first smaller than or equal to second.
Otherwise, output NO
    ○ Don’t use < operator to compare strings. Use loops
● Input ⇒ Output
    ○ aaa aaa ⇒ YES
    ○ aaaaa aa ⇒ NO
    ○ abc d ⇒ YES
    ○ dddddddddddddd xyz ⇒ YES
    ○ azzzzzzzz za ⇒ YES
    ○ za azzzzzzzz ⇒ NO
*/

int main(){
    string str1, str2;
    cin >> str1 >> str2;

    int sz1 = (int)str1.size();
    int sz2 = (int)str2.size();

    for(int i=0; i<sz1 && i<sz2; i++){
        if(str1[i]<str2[i]){
            cout << "Yes";
            return 0;
        }
        else if(str1[i]>str2[i]){
            cout << "No";
            return 0;
        }
    }

    if(sz1<sz2)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
