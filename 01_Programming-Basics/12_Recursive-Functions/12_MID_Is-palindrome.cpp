#include<iostream>
using namespace std;



bool is_palindrome(int arr[], int len, int start_pos=0){
    if(len-1 == start_pos || len == start_pos)
        return true;

    if(arr[len-1] != arr[start_pos])
        return false;

    is_palindrome(arr, len-1, start_pos+1);
}


int main(){
    int arr[100] {1, 2, 3, 5, 5, 3, 2, 1};

    cout << is_palindrome(arr, 8);

    return 0;
}

