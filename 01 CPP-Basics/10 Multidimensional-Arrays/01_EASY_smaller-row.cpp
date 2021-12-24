#include<iostream>
using namespace std;

/*
● Read integers N, M, then Read matrix NxM. Then read Q for Q queries.
● Each query is 2 integers: first and 2nd row indices (1-based)
● Compare the 2 rows and print YES if first row < 2nd for all the row values
● Input ⇒ Output
    ○ 3 4
    ○ 8 16 9 52
    ○ 3 15 27 6
    ○ 14 25 29 10
    ○ 3
    ○ 1 2 ⇒ NO
    ○ 2 3 ⇒ YES
    ○ 1 3 ⇒ NO
*/

int main(){
    int const MAX = 100;
    int matrix[MAX][MAX];

    //8 16 9 52 3 15 27 6 14 25 29 10

    int row,col;
    cin >> row >> col;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++)
            cin >> matrix[i][j];
    }

    int q;
    cin >> q;
    while(q--){
        int r1,r2;
        cin >> r1 >> r2;
        bool flag = true;
        for(int j=0; j<col; j++){
            if(matrix[r1-1][j] >= matrix[r2-1][j]){
                cout << "No\n";
                flag = false;
                break;
            }
        }
        if(flag)
            cout << "Yes\n";

    }


    return 0;
}

