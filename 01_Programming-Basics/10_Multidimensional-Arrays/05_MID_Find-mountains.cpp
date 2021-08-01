#include<iostream>
using namespace std;

/*
● Read integers N, M, then Read matrix NxM. Print all positions that are
mountain. Position is mountain if its value > 8 neighbours values
● Code smartly
● Input
    ○ 3 3
    ○ 8 6 1
    ○ 3 2 9
    ○ 1 6 4
● Output
    ○ 0 0 (8 > 6, 3, 2)
    ○ 1 2 (9 > 1, 2, 5, 4, 6)
*/

int main(){
    int const MAX = 100;
    int matrix[MAX][MAX];

    //8 6 1 3 2 9 1 6 4

    int row,col;
    cin >> row >> col;
    for(int r=0; r<row; r++){
        for(int c=0; c<col; c++)
            cin >> matrix[r][c];
    }

    int dr[]{-1,-1,-1,0,0,1,1,1};
    int dc[]{-1,0,1,-1,1,-1,0,1};
    for(int r=0; r<row; r++){
        for(int c=0; c<col; c++){
            int d = 0;
            int mountain = matrix[r][c];
            bool is_mount = true;
            while(d<8){
                int nr = dr[d] + r;
                int nc = dc[d] + c;
                if(0<=nr && nr < row && 0 <= nc && nc < col){
                    if(mountain<matrix[nr][nc]){
                        is_mount = false;
                        break;
                    }
                }
                d++;
            }
            if(is_mount)
                cout << r << " " << c << endl;
        }
    }

    return 0;
}

