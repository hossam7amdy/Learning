#include<iostream>
#include<algorithm>
using namespace std;

/// https://codeforces.com/contest/682/problem/A

int main(){

    int n,m;
    long long int c=0;
    cin >> n >> m;

    if(n+m<5)
    {
        cout << 0;
        return 0;
    }

    int k = min(n,m);
    int l = max(n,m);
    for(int i = 1; i<=k; i++, c++)
    {
        int comp = 5;
        if(i<5)
            comp = comp - i;
        else if(i>5)
            comp = comp - (i%comp);
        c += ((l-comp) / 5);
    }

    cout << c;

    return 0;
}
