#include<iostream>
using namespace std;

/*
● void array_increment(int arr[], int len)
● The function increments each arr[i] with i
● E.g. for input
    ○ [1, 2, 5, 9] it be [1+0, 2+1, 5+2, 9+3]
    ○ 1 8 2 10 3 ⇒ 1 9 4 13 7
*/

void array_increment(int arr[], int len){
    if(len==0)
        return;

    array_increment(arr, len-1);
    arr[len-1] += len-1;
}

int main(){
    int arr[100] {1, 8, 2, 10, 3};

    array_increment(arr, 5);

    for(int i=0; i<5; i++)
        cout << arr[i] << " ";

    //array_increment(arr, 5) => arr[4] + 4 => 3 +4 = 7
    //array_increment(arr, 4) => arr[3] + 3 => 10+3 = 13
    //array_increment(arr, 3) => arr[2] + 2 => 2 + 2 = 4
    //array_increment(arr, 2) => arr[1] + 1 => 8 + 1 = 9
    //array_increment(arr, 1) => arr[0] + 0 => 1 + 0 = 1
    //array_increment(arr, 0) => nothing


    return 0;
}
