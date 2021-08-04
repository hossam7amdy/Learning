#include<iostream>
using namespace std;

/*
● Int sum(int arr[], int len);
● Write a function that computes array sum
● Input 1, 8, 2, 10, 3 ⇒ 24
*/

int arr_sum(int arr[], int len){
    if(len==1)
        return arr[0];

    int sum = arr_sum(arr, len-1);
    return sum + arr[len-1];
}

int main(){
    int arr[100] {1, 8, 2, 10, 3, 5, 9};

    cout << arr_sum(arr, 5);

    // arr_sum(arr, 5) => 21 + 3 = 24
    // arr_sum(arr, 4) => 11 + 10 = 21
    // arr_sum(arr, 3) => 9 + 2 = 11
    // arr_sum(arr, 2) => 1 + 8 = 9
    // arr_sum(arr, 1) => 1

    return 0;
}
