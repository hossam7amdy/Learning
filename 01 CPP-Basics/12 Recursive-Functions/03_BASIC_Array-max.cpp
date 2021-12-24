#include<iostream>
using namespace std;

/*
● int arr_max(int arr[], int len);
● Write a function that computes array maximum
● Input 1, 8, 2, 10, 3 ⇒ 10
*/

int arr_max(int arr[], int len){
    if(len==1)
        return arr[0];

    int result = arr_max(arr, len-1);
    return max(result, arr[len-1]);
}

int main(){
    int arr[100] {1, 18, 2, 10, 3};

    cout << arr_max(arr, 5);

    //arr_max(arr, 5) => max(18, 3) => 18
    //arr_max(arr, 4) => max(18, 10)=> 18
    //arr_max(arr, 3) => max(18, 2) => 18
    //arr_max(arr, 2) => max(1, 18) => 18
    //arr_max(arr, 1) => 1


    return 0;
}
