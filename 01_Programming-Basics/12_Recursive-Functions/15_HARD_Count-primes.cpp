#include<iostream>
using namespace std;

/*
● Int count_primes(int start, int end);
○ Compute how many primes between start & end, inclusive indices
● Don’t use loops at all
● Input
○ 10 20 ⇒ 4
○ 10 200 ⇒ 42
● Can u compute answer for [10, 5000000]?
*/

int is_prime(int n, int i=2){
    if(n<=1)
        return 0;

    if(i==n)
        return 1;

    if(n%i==0)
        return 0;

    return is_prime(n, i+1);
}

int count_primes(int st, int en){
    if(st==en+1)
        return 0;

    int cnt = count_primes(st+1, en);
    return cnt + is_prime(st);
}

int main(){

    cout << count_primes(10, 18000);

    return 0;
}
