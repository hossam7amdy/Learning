#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;

/// https://codeforces.com/contest/439/problem/B

string ToString(const int &num)
{
    ostringstream oss;
    oss << num;
    return oss.str();
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    string res = "";
    for(const auto &val : v)
    {
        res += ToString(val * x);
        x -= (x!=1);
    }

    cout << res;

    return 0;
}
