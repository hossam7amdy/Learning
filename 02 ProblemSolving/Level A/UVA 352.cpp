#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=288

int n;
int const MAX(26);
char grid[30][30];
vector< vector<bool> > visited(MAX, vector<bool>(MAX,false));


bool valid_dir(int ni, int nj){
    return(0<=ni && ni<n && 0<=nj && nj<n);
}

int di[] {-1,-1,-1,0,0,1,1,1};
int dj[] {-1,0,1,-1,1,-1,0,1};

void dfs(int r, int c){

    if(visited[r][c])
        return;

    visited[r][c] = true;

	for(int i=0; i<8; i++){
        int nr = r + di[i];
        int nc = c + dj[i];
        if(!valid_dir(nr, nc))
            continue;

		if(grid[nr][nc]=='1')
			dfs(nr,nc);
	}
	return;
}

int ConnectedComponenetsCnt(){
	int cnt = 0;

	for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j] && grid[i][j]=='1'){
                dfs(i,j);
                ++cnt;
            }
        }
	}
	return cnt;
}

void reset_visited(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            visited[i][j]=false;
    }
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
	freopen("out.txt", "wt", stdout);
#endif

    int Case = 1;
    while(scanf("%d", &n)==1){
        for(int i=0; i<n; i++){
            scanf("%s", grid[i]);
        }
        cout << "Image number " << Case++ << " contains " << ConnectedComponenetsCnt() << " war eagles.\n";
        reset_visited();
    }

    return 0;
}
