#include<bits/stdc++.h>
using namespace std;

/// https://codeforces.com/contest/88/problem/B

int main()
{
    vector< vector<char> > v(2 ,vector<char>(2));
    for(int i=0; i<2; ++i)
    {
        for(int j=0; j<2; ++j)
            cin >> v[i][j];
    }

    auto it = find(v.begin(),v.end(), 'd');

    //if(it!=v.end())
    //    cout << "found\n";

    //cerr<<"Time : "<<(float)clock()/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}
