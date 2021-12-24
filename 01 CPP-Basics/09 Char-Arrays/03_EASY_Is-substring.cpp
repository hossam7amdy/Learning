#include <iostream>
using namespace std;

/*
● Read 2 strings input and str. Print YES if the given str is a substring for the
string. Otherwise, print NO
● Input ⇒ Outputs
    ○ ABCDEFG ABCD ⇒ YES
    ○ ABCDEFG ABCDEF ⇒ YES
    ○ ABCDEFG EFG ⇒ YES
    ○ ABCDEFG DEFG ⇒ YES
    ○ ABCDEFG BCD ⇒ YES
    ○ ABCDEFG DEF ⇒ YES
    ○ ABCDEFG ACEG ⇒ NO
    ○ ABCDEFG DG ⇒ NO
    ○ ABCDEFG GD ⇒ NO
    ○ ABCDEFG ABCDEFG ⇒ YES
*/

int main(){
    string str, sub;
    cin >> str >> sub;

    //Dr.Mustafa coded it in a very interesting style
    //Don't forget to revise it.

    //Don't forget to check the size of each one before comparison
    //He mentioned casting when it comes to use size() func
    string is_sub;
    int cnt = 0;
    for(int i=0; i<str.size(); i++){

        if(str[i]==sub[0]){
            is_sub = str[i];

            for(int j=i+1,k=1;k<sub.size();k++,j++){
                if(str[j]!=sub[k])
                    break;

                is_sub+=str[j];
            }
        }
    }

    //Don't use compare strings

    if(is_sub == sub)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
