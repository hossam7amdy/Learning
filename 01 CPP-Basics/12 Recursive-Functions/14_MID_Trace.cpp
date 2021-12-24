#include<iostream>
using namespace std;

void do_something(int n){
    if(n){
        cout << n%10 << " ";
        do_something(n/10);

    }
}

int main(){

    do_something(123456);

    //do_something(123456) = 6
    //do_something(12345) = 5
    //do_something(1234) = 4
    //do_something(123) = 3
    //do_something(12) = 2
    //do_something(1) = 1
    //do_something(0) = break

    //do_something(123456)
    //do_something(12345)
    //do_something(1234)
    //do_something(123)
    //do_something(12)
    //do_something(1)
    //do_something(0) = break and print 1 2 3 4 5 6

    return 0;
}
