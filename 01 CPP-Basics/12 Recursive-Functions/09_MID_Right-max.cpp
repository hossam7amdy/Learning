#include<iostream>
using namespace std;

/*
● Given array, change each element at position i to be the maximum of
numbers from index i to end of array
● E.g. input 1 3 5 7 4 2 ⇒ [7, 7, 7, 7, 4, 2]
● Void right_max(int arr[], int len, int start_position = 0);
*/


void right_max_v1(int arr[], int len, int start_position = 0){
    if(start_position==len-1)
        return;

    right_max_v1(arr, len, start_position+1);
    arr[start_position] = max(arr[start_position], arr[start_position+1]);
}


void right_max_v2(int arr[], int len){
    if(len==1)
        return;

    arr[len-2] = max(arr[len-2], arr[len-1]);
    right_max_v2(arr, len-1);
}


int main(){
    int arr[100] {1, 8, 2, 10, 3 };

    right_max_v1(arr, 5);

    for(int i=0; i<5; i++)
        cout << arr[i] << " ";

    return 0;
}
