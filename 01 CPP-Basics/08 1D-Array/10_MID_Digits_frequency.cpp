#include <iostream>
using namespace std;

/*
● Read an Integer N, then read N <= 200 integers. For all the digits from 0 to 9,
we want to know how many times appeared.
    ○ Input 2 78 307
    ○ Output:
○ 0 1
○ 1 0 [digit 1 never appeared]
○ 2 0
○ 3 1
○ 4 0
○ 5 0
○ 6 0
○ 7 2 [digit 7 appeared twice]
○ 8 1
○ 9 0
*/

main(){
    const int MAX = 10;
    int arr[MAX]={0},n;

    cin >> n;

    for(int i=0; i<n; i++){
        int value;
        cin >> value;
        if(value==0) // I missed this step thanks Dr.Mustafa
            arr[0]++;
        while(value){
            arr[value%10]++;
            value/=10;
        }
    }

    for(int i=0; i<10; i++)
        cout << i << " " << arr[i] << endl;


    return 0;
}
