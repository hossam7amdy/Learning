#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/// https://codeforces.com/problemset/problem/816/B

int main()
{
    const int MAX {200001};
    int n, k, q, s, e;
    scanf("%d%d%d", &n,&k,&q);
    vector<int> v(MAX,0);
    while(n--)
    {
        scanf("%d%d", &s,&e);
        v[s]++;
        v[e+1]--;
    }

    for(int i=1; i<MAX; i++)
        v[i] = v[i] + v[i-1];

    for(int i=1; i<MAX; i++)
        v[i] = (k<=v[i]);

    for(int i=1; i<MAX; i++)
        v[i] = v[i] + v[i-1];

    while(q--)
    {
        scanf("%d%d", &s,&e);
        printf("%d\n", v[e]-v[s-1]);
    }

    return 0;
}
