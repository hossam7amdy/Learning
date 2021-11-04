#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/// https://codeforces.com/contest/810/problem/B

bool cmp(const pair<int, int>& p1, const pair<int, int> &p2)
{
    //if(p1.second > p2.second)
     //   return p1.second > p2.second;
    return p1.first > p2.first;
}

int main()
{
    int n, f;
    cin >> n >> f;
    vector<pair<int, int> > v(n);

    for(int i=0; i<n; i++)
        cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end(), cmp);

    long long int sum = 0;
    for(int i=0; i<f; ++i)
    {
        cout << v[i].first << " " << v[i].second << endl;
        if((2 * v[i].first)<=v[i].second)
            sum += (2 * v[i].first);
        else
            sum += v[i].second;
    }

    for(int i=f; i<n; ++i)
    {
        cout << v[i].first << " " << v[i].second << endl;
        if(v[i].first<=v[i].second)
            sum += v[i].first;
        else
            sum += v[i].second;
    }

    printf("%d", sum);

    return 0;
}
