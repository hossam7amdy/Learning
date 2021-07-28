#include <iostream>
using namespace std;

/*
● Read 2 strings input and str. Print YES if the given str is a prefix for the string.
    Otherwise, print NO
● Input ⇒ Outputs
    ○ ABCDEFG ABCD ⇒ YES
    ○ ABCDEFG EFG ⇒ NO
*/

int main(){
    string str, prfx;
    cin >> str >> prfx;

    //missing a condition if(prfx>str)
    //What if both are an empty strings

    for(int i=0; i<prfx.size(); i++){
        if(prfx[i]!=str[i]){
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";

    return 0;
}
