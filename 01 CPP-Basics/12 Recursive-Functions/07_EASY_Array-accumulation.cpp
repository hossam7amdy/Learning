#include<iostream>
using namespace std;

/*
● Given an array we want to accumulate it as following:
    ○ Input 1 2 3 4 5 6
    ○ Output array
■ 1, 1+2, 1+2+3, 1+2+3+4, 1+2+3+4+5, 1+2+3+4+5+6
■ 1, 3, 6, 10, 15, 21
    ○ That is return arr[i] = sum of all numbers from 0 to i
● void accumulate_arr(int arr[], int len);
    ○ Input 1 8 2 10 3 ⇒ 1 9 11 21 24
*/

void accumulate_arr(int arr[], int len){
    if(len==1)
        return;

    accumulate_arr(arr, len-1);
    arr[len-1] += arr[len-2];
}

int main(){
    int arr[100] {1, 8, 2, 10, 3};

    accumulate_arr(arr, 5);

    for(int i=0; i<5; i++)
        cout << arr[i] << " ";

    //accumulate_arr(arr, 5) => arr[5-1] = 21+ 3 = 24
    //accumulate_arr(arr, 4) => arr[4-1] = 11 +10= 21
    //accumulate_arr(arr, 3) => arr[3-1] = 9 + 2 = 11
    //accumulate_arr(arr, 2) => arr[2-1] = 8 + 1 = 9
    //accumulate_arr(arr, 1) => nothing just break;

    return 0;
}
