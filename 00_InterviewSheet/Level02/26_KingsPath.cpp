#include<bits/stdc++.h>
using namespace std;

/// https://codeforces.com/contest/242/problem/C

const int MAX = 8;
int dRow[MAX] {-1,-1,-1,0,1,1,1,0};
int dCol[MAX] {-1,0,1,1,1,0,-1,-1};

set<pair<int, int>> visited;
set<pair<int,int>> board;

int BFS(const pair<int, int>& s, const pair<int, int>& d){

    queue< pair<int,int> > q;
    q.push(s);
    visited.insert(s);

    int steps = 1, sz = 1;
    for(;!q.empty();++steps, sz = q.size()){
        while(sz--){

            pair<int,int> curr = q.front();
            q.pop();

            for(int k=0; k<MAX; ++k){
                pair<int, int> newp;
                newp.first = curr.first + dRow[k];
                newp.second = curr.second + dCol[k];

                if(!board.count(newp) || visited.count(newp))
                    continue;

                q.push(newp);
                visited.insert(newp);

                if(newp == d)
                    return steps;
            }
        }
    }
    return -1;
}

int main()
{
    // little faster reading
	std::ios_base::sync_with_stdio(false);

    int x1,y1,x2,y2,n;
    cin >> x1>>y1>>x2>>y2>>n;

    pair<int,int> s{make_pair(x1,y1)},d{make_pair(x2,y2)};

    while(n--){
        int a,b,c;
        cin >>a>>b>>c;
        for(int j=b; j<=c; ++j)
            board.insert({a,j});
    }

    cout << BFS(s,d);

    //cerr<<"Time : "<<(float)clock()/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}
