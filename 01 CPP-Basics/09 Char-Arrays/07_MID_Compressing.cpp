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
    //He uses => str += "$"

    bool st_group = true;
    int cnt = 1, sz = (int)str.size();
    for(int i=0; i<sz; i++){
        if(str[i]!=str[i+1]){
            if(!st_group)
                cout << '_';

        cout << str[i] << cnt;
        cnt = 0; //reset the counter
        st_group = false; // not first anymore
        }
        cnt++;
    }



    return 0;
}
