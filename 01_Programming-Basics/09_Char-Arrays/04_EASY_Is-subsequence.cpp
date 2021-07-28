#include <iostream>
using namespace std;

/*
● Read 2 strings input and str. Print YES if the given str is a subsequence for
the string. Otherwise, print NO
● Input ⇒ Outputs
    ○ ABCDEFG ABCD ⇒ YES
    ○ ABCDEFG ABCDEF ⇒ YES
    ○ ABCDEFG EFG ⇒ YES
    ○ ABCDEFG DEFG ⇒ YES
    ○ ABCDEFG BCD ⇒ YES
    ○ ABCDEFG DEF ⇒ YES
    ○ ABCDEFG ACEG ⇒ YES
    ○ ABCDEFG DG ⇒ YES
    ○ ABCDEFG GD ⇒ NO
    ○ ABCDEFG ABCDEFG ⇒ YES

*/

int main(){
    string str, sub;
    cin >> str >> sub;

    //You can get rid of nested loops easily think deeper
    //HINT: compare with big one!
    int j = 0;
    for(int i=0; i<sub.size(); i++){
        for(;j<str.size(); j++){
            if(sub[i]==str[j])
                break;
            }
        if(j==str.size()){
            cout << "No";
            return 0;
        }
    }


    cout << "Yes";

    return 0;
}
