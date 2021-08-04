#include<iostream>
using namespace std;

/*
● double average(int arr[], int len);
● Write a function that computes array average
○ Don’t divide by length in the main
● Input 1, 8, 2, 10, 3 ⇒ 4.8
*/

double average(int arr[], int len){
    if(len==1)
        return arr[0];

    double avg = average(arr, len-1);
    //let's multiply by last index to remove the fraction and start over.
    avg *= len-1; //Be careful this line should not execute in the last operation.
    return (avg + arr[len-1]) /len;
}

int main(){
    int arr[100] {1, 8, 2, 10, 3};

    cout << average(arr, 5);

    return 0;
}
