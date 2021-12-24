#include<iostream>
using namespace std;

/*
● Write a function that sums only the first N elements in an array.
● Define its signature
● Input [1, 3, 4, 6, 7], 3 ⇒ 8 (1+3+4)
*/



int prefix_sum(int arr[], int n){
    if(n==0)
        return 0;

    return arr[n-1] + prefix_sum(arr, n-1);
}


int main(){
    int arr[100] {1, 3, 4, 6, 7};

    cout << prefix_sum(arr, 3);

    return 0;
}
