#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;

/// https://codeforces.com/contest/492/problem/B

int main(){

    int n,l;
    cin >> n >> l;
    vector<double> v(n);

    for(int i=0; i<n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    double st = v[0] - 0;
    double en = l - v[n-1];
    double dis = 0;

    for(int i=1; i<n; i++)
        dis = max(dis, (v[i] - v[i-1]));

    dis/=2;
    cout << setprecision(10);
    cout << fixed;
    if(st>=en && st>=dis)
        cout << st;
    else if(en>=st && en>=dis)
        cout << en;
    else
        cout << dis;

    return 0;
}
