#include <iostream>
using namespace std;

/*
● Read a string of letters and then compress each group of same letter
    ○ E.g. if the sub-string is cccc ⇒ c4
    ○ Use _ between each group
● Input ⇒ Outputs
    ○ ccccDDDxxxxxxxxe ⇒ c4_D3_x8_e1
    ○ xxxxxxxx ⇒ x8
*/

int main(){
    string str;
    cin >> str;

    //There is a bug. I think there is a better solution.

    int cnt = 1;
    for(int i=0; i<(int)str.size(); i++){
        if(str[i]==str[i+1])
            cnt++;
        else{
            cout << str[i] << cnt;
            cnt = 1;
            if(i<(int)str.size())
                cout << '-';
        }
    }



    return 0;
}
