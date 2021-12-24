#include<iostream>
using namespace std;

/*
● Implement fibonacci: Int fibonacci(int n)
    ○ Recall fibonacci sequence: 1 1 2 3 5 8 13 21 35
    ○ E.g. fibonacci(7) = 13
    ○ Recall that: fibonacci(n) = fibonacci(n-1) + fibonacci(n-2). E.g. fib(7) = fib(6)+fib(5) =13
■ So it calls 2 subproblems of its type
● Can u compute fibonacci(40)? fibonacci(50)? Why? Any work around? Hint: Array
*/

int fib(int n){
    if(n<=2)
        return 1;
    return fib(n-1) + fib(n-2);
}

/*
int arr[100];
void ass_values(int arr[], int n){
    if(n==0)
        return;

    ass_values(arr, n-1);
    if(n==1 || n==2)
        arr[n-1] = 1;
    else
        arr[n-1] = arr[n-2] + arr[n-3];
}

int fib_big(int n){
    ass_values(arr, n);
    return arr[n-1];
}
*/

int main(){
    for(int i=1; i<21; i++)
        cout << fib(i) << " ";

    return 0;
}
