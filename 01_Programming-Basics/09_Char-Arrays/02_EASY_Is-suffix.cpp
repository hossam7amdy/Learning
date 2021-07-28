#include <iostream>
using namespace std;

/*
● Read 2 strings input and str. Print YES if the given str is a suffix for the string.
Otherwise, print NO
● Input ⇒ Outputs
    ○ ABCDEFG GD ⇒ NO
    ○ ABCDEFG ABCDEFG ⇒ YES
*/

int main(){
    string str, sufx;
    cin >> str >> sufx;

    //missing a condition if(prfx>str)
    //Can you make more readable than that?

    for(int i=sufx.size()-1,j=str.size()-1; i>=0; i--,j--){
        if(sufx[i]!=str[j]){
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";

    return 0;
}
