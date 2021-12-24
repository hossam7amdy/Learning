#include<iostream>
using namespace std;

/*
● Given a 2D array of numbers, all of them are positive distinct. Robot start from
(0, 0). It can move to the right or left or diagonal. It will select one direction:
the maximum. Print the total path sum of this robot
○ int path_sum(int grid[100][100], int row, int col, int ROWS, int COLS)
● Input
    ○ 3 3
    ○ 1 7 8
    ○ 2 10 11
    ○ 20 5 9
● Output: 31 (from 1 + 10 + 11 + 9)
    ○ Robot start at (0, 0). 3 possible values (2, 7, 10). Max 10, so go to this cell
    ○ Then 3 possible values (5, 9, 11). Go to 11. Then only 9 available
*/

int di[] {0,1,1};
int dj[] {1,0,1};

int path_sum(int grid[100][100],int ROWS, int COLS, int row=0, int col=0){
    int sum = grid[row][col];

    if(row==ROWS-1 && col==COLS-1)
        return sum;

    int max_value, best_idx=-1;
    for(int d=0; d<3; d++){
        int nr = row+di[d];
        int nc = col+dj[d];
        if(nr>=ROWS || nc>=COLS)
            continue;

        if(max_value<grid[nr][nc])
            max_value = grid[nr][nc], best_idx = d; //store the best co-ordinate
    }
    row += di[best_idx]; //apply them to the next call
    col += dj[best_idx];

    return sum + path_sum(grid, ROWS,COLS, row, col);
}

int main(){
    int grid[100][100] {{1, 7, 8},
                        {2, 10, 11},
                        {20, 5, 9}};


    cout << path_sum(grid, 3,3);

    return 0;
}
