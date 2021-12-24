#include<iostream>
using namespace std;

/*
● A 3n+1 goes as following
● Start from a number n
● If this number is even, next number in sequence is n / 2
● If this number is odd, next number in sequence is 3 * n + 1
● If this number is 1 = end of sequence
● E.g. Start from 5: => 6
● E.g. Start from 6: => 9
● E.g. Start from 9: => 20
● Write a recursive function to print it
*/

int len_of_3nplus_1(int num){
    if(num==1) //base-case
        return 1;

    if(num%2==0)
        return 1 + len_of_3nplus_1(num/2);
    else
        return 1 + len_of_3nplus_1(3*num+1);
}

int main(){

    cout << len_of_3nplus_1(9);

    return 0;
}
