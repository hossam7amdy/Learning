#include<iostream>
using namespace std;

/*
● Write a function that sums only the last N elements in an array.
● Define its signature
● Input [1, 3, 4, 6, 7], 3 ⇒ 17 (4+6+7)
*/



int suffix_sum(int arr[], int len, int n){
    if(n==0)
        return 0;

    return arr[len-1] + suffix_sum(arr, len-1, n-1);
}


int main(){
    int arr[100] {1, 3, 4, 6, 7};

    cout << suffix_sum(arr, 5, 3);

    return 0;
}
