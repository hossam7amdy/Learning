#include<iostream>
using namespace std;

/*
● Read 2 integers N and M, then Read matrix NxM.
● Then read integer Q, for Q queries.
● For each query read 4 integers: i j r c
    ○ Represents a grid (submatrix): top left (i, j) and (r, c) for (# rows, # cols)
● For each query, print how many prime numbers in the requested grid.
    ○ Each query should be answered using nested loops maximum not more
    ○ In future: with smart precomputation it can be done without loops
■ It is called Image integral in Computer Vision field.

Input ⇒ Output
    ○ 3 4
    ○ 8 2 9 5
    ○ 3 2 27 6
    ○ 7 8 29 22

    ○ 2
    ○ 1 0 2 2 ⇒ 3 (primes 3, 2, 7 in rectangle (0, 1) (2, 1) )
    ○ 0 1 2 3 ⇒ 3 (primes 2, 5, 2 in rectangle (0, 1) (1, 3) )

*/

int main(){
    int const MAX = 100;
    int matrix[MAX][MAX];

    //3 4 8 2 9 5 3 2 27 6 7 8 29 22 2 1 0 2 2 0 1 2 3

    int row,col;
    cin >> row >> col;
    for(int r=0; r<row; r++){
        for(int c=0; c<col; c++)
            cin >> matrix[r][c];
    }

    int q;
    cin >> q;
    while(q--){
        int i,j,r,c,cnt=0;
        cin >> i >> j >> r >> c;
        int st = i * col + j; //Let's flatten it to avoid extra loop
        int en = r * col + c;
        for(;st<en;st++){ // iterating over it
            int ni = st/col; // converting back to 2D
            int nj = st%col;
            r+=i; //the actual start and end of the sub-matrix
            c+=j;
            if(i<=ni && ni<r && j<=nj && nj<c){ //to make sure that we are in the sub-matrix (this line exhausted me)
                int value=matrix[ni][nj];
                if(value==2){
                    cnt++;
                    continue;
                }
                bool flag = true;
                for(int i=2; i<value; i++){ //is it a valid prime
                    if(value%i==0){
                        flag = false;
                        break;
                    }
                }
                if(flag)
                    cnt++;
            }

        }
        cout << cnt << "\n";
    }



    return 0;
}

