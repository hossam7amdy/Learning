#include<iostream>
using namespace std;

/*
● A 3n+1 goes as following
● Start from a number n
● If this number is even, next number in sequence is n / 2
● If this number is odd, next number in sequence is 3 * n + 1
● If this number is 1 = end of sequence
● E.g. Start from 5: 5 16 8 4 2 1
● E.g. Start from 6: 6 3 10 5 16 8 4 2 1
● E.g. Start from 9: 9 28 14 7 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
● Write a recursive function to print it
*/

void sequence(int num){
    cout << num << " ";

    if(num==1) //base case
        return;

    if(num%2==0)
        sequence(num/2);
    else
        sequence(3*num+1);
}

int main(){

    sequence(9);

    return 0;
}
