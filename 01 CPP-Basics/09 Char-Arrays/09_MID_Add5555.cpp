#include <iostream>
using namespace std;

/*
● Read a very long string of digits (at least 6 digits), and add 5555 to it.
    ○ Don’t convert to integer, as integer has max limit for values
● Input ⇒ Outputs
    ○ “100000” ⇒ “105555”
    ○ “10001234” ⇒ “10006789”
    ○ “3001072” ⇒ “3006627”
    ○ “10999999999” ⇒ “11000005554”
    ○ “999999999999999999999999999999999” ⇒ “1000000000000000000000000000005554”
*/

int main(){
    string str;
    cin >> str;
    int sz = (int)str.size(); // length of str
    int arr[sz+1]={0}; // new int array of same length+1 to handle carry

    for(int i=0; i<sz; i++){ //convert the string array to an integer one
        arr[sz-i]=(int)(str[sz-i-1]-'0');
        if(i<4)  //Add 5 to first 4 LSBs
            arr[sz-i] += 5;

    }

    for(int i=sz; i>0; i--){ //Handle carry
        if(arr[i]>9){ // if there is a carry move to to next position
            arr[i]-=10;
            arr[i-1]+=1;
            }
    }


    if(arr[0]!=0) // check if there is a carry print it
        cout << arr[0];
    for(int i=1; i<sz+1; i++){
        cout << arr[i];
    }

    cout << "\n****************************************\n";
    // Dealing with is directly without creating a new integer array
    sz = str.size();
    int carry = 0;
    for(int i=0; i<sz; i++){
        int value = (int)(str[sz-1-i]-'0') + carry;
        if(i<4)
            value += 5;

        carry=(value>9);
        if(carry)
            value-=10;

        str[sz-1-i] = (char)value + '0';
    }

    if(carry) //nice trick to handle the carry
        cout << 1;
    cout << str;

    return 0;
}
