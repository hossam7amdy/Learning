#include<iostream>
using namespace std;

/*
● int my_pow(int value, int p = 2)
● Return value * value ….. * value p times
● E.g. my_pow(7, 3) = 7 * 7 * 7 = 343
● Note: if p = 0, answer is 1
*/

int my_pow(int value, int p = 2){
    if(p==0)
        return 1;

    return value * my_pow(value, p-1);
}

int main(){

    cout << my_pow(7, 3);

    return 0;
}
