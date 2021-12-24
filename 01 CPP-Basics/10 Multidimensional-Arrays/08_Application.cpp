#include<iostream>
using namespace std;


int main(){
    int const MAX = 100;
    int matrix[100][100]{0};
    int n;
    cin >> n;

    int player = 1;
    while(true){
        int r,c;
        if(player==1){
            cout << "Played x turn. Enter empty location (r, c): ";
            cin >> r >> c;
            --r;
            --c;
            if(r>=n || c>=n || matrix[r][c]!=0){ //OR gate
                cout << "Invalid input. Try again\n";
                continue;
            }
            matrix[r][c] = 1;
            player = 2;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(matrix[i][j]==0)
                        cout << ". ";
                    else if(matrix[i][j]==1)
                        cout << "x ";
                    else
                        cout << "o ";
                }
                cout << "\n";
            }
        }

        if(player==2){
            cout << "Played o turn. Enter empty location (r, c): ";
            cin >> r >> c;
            --r;
            --c;
            if(!(matrix[r][c]==0 && r<n && c<n)){ //NAND gate
                cout << "Invalid input. Try again\n";
                continue;
            }
            matrix[r][c] = 2;
            player = 1;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(matrix[i][j]==0)
                        cout << ". ";
                    else if(matrix[i][j]==1)
                        cout << "x ";
                    else
                        cout << "o ";
                }
                cout << "\n";
            }
        }
    }

    return 0;
}

