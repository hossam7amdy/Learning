#include<iostream>
#include<vector>
#include <cstring>
using namespace std;

/// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3104

int const MAX = 100;
char grid[MAX][MAX];
bool visited[MAX][MAX]{0};
int N;

void dfs(int r, int c){
    if(r<0||c<0||r==N||c==N)return;
    if(grid[r][c]=='.'||visited[r][c])return;
    visited[r][c]=1;

    // we only go vertical or horizontal.
    dfs(r-1,c);
    dfs(r+1,c);
    dfs(r,c-1);
    dfs(r,c+1);
}

int ConnectedComponentCnt(){
    int c = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j]&&grid[i][j]=='x'){
                c++;
                dfs(i,j);
            }
        }
    }
    return c;
}


int main(){
    int T;
    int Case = 1;
    cin >> T;
    while(T--){
        memset(visited, 0, sizeof(visited));
        cin >> N;
        for(int i=0; i<N; i++)
            cin >> grid[i];

        int Ships = ConnectedComponentCnt();
        cout << "Case " << Case++ << ": " << Ships << "\n";
    }

    return 0;
}
