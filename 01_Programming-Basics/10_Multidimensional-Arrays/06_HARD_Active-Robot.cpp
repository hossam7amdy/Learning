#include<iostream>
using namespace std;

/*
● Read integers N, M represents a matrix. A robot start at cell (0, 0).
● Read integer K, then K commands. Each command is 2 values
○ Direction from 1 to 4: up, right, down, left
○ Steps: a number to number steps to take in the direction. Steps [1, 1000000000]
○ If the robot hits the wall during the move, it circulates in the matrix.
○ For every command, print where is the robot now
● Input
    ○ 3 4 4 2 1 3 2 4 2 1 3
■ 2 1 means to right 1 step - 3 2 means down 2 steps
● Output
    ○ (0, 1) (2,1) (2, 3) (2, 3)

*/

int main(){
    int row,col;
    cin >> row >> col;

    int dr[]{-1,0,1,0};
    int dc[]{0,1,0,-1};
    int k;
    cin >> k;
    int r = 0, c = 0; //start at (0, 0)
    while(k--){
        int dir, steps;
        cin >> dir >> steps;
        dir-=1;

        //Can it be more shorter than this?
        if(dir==0){ //UP
            steps%=row;
            r += dr[0]*steps;
            if(r<0)
                r+=row;
        }
        else if(dir==1){ //Right
            steps%=col;
            c += dc[1]*steps;
            if(c>=3)
                c+=col;
        }
        else if(dir==2){//Down
            steps%=row;
            r += dr[2]*steps;
            if(r>=3)
                r-=row;
        }
        else if(dir==3){//Left
            steps%=col;
            c += dc[3]*steps;
            if(c<0)
                c+=col;
        }

       cout << r << " " << c << endl;
    }

    return 0;
}

