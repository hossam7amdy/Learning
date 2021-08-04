#include<iostream>
using namespace std;

/*
● Given array, change each element at position i to be the maximum of
numbers from 0 to index i
● E.g. input 1 3 5 7 4 2 ⇒ [1, 3, 5, 7, 7, 7]
● Void left_max(int arr[], int len);
*/

void left_max(int arr[], int len){
    if(len==1)
        return;

    left_max(arr, len-1);
    arr[len-1] = max(arr[len-1], arr[len-2]);
}


int main(){
    int arr[100] {1, 3, 5, 7, 4, 2};

    left_max(arr, 6);

    for(int i=0; i<6; i++)
        cout << arr[i] << " ";

    //left_max(arr, 6) => arr[5] = max(arr[5], arr[4]) => arr[5] = max(2, 7) = 7
    //left_max(arr, 5) => arr[4] = max(arr[4], arr[3]) => arr[4] = max(4, 7) = 7
    //left_max(arr, 4) => arr[3] = max(arr[3], arr[2]) => arr[3] = max(7, 5) = 7
    //left_max(arr, 3) => arr[2] = max(arr[2], arr[1]) => arr[2] = max(5, 3) = 5
    //left_max(arr, 2) => arr[1] = max(arr[1], arr[0]) => arr[1] = max(3, 1) = 3
    //left_max(arr, 1) => nothing just break;

    return 0;
}
