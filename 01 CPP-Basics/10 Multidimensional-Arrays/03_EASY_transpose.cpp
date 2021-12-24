#include<iostream>
using namespace std;

/*
● Read integers N, M, then Read matrix NxM. Compute another array, the
transpose
● Input/output as in image
*/

int main(){
    int const MAX = 100;
    int matrix[MAX][MAX];

    //8 16 9 52 3 15 27 6 14 25 29 10

    int row,col;
    cin >> row >> col;
    for(int r=0; r<row; r++){ //transposing on the fly
        for(int c=0; c<col; c++)
            cin >> matrix[c][r];
    }

    int temp = row;
    row = col;
    col = temp;

     for(int r=0; r<row; r++){
        for(int c=0; c<col; c++)
            cout << matrix[r][c] << " ";
        cout << "\n";
    }


    return 0;
}

