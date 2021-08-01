#include<iostream>
using namespace std;

/*
● Read 3 numbers: DEPTH, ROWS, COLS the dimensions of 3D array
● Then read integer either 1 (convert 3D to 1D) or 2 (1D to 3D)
● If input was 1, then read 3 integers d, r, c then convert to position in 1D array
● If input was 2, then read 1 integer position, then convert to 3D array position
● Try to generalize if we have e.g. 6D array
● Input ⇒ Outputs
    ○ 3 4 5 1 1 0 0 ⇒ 20
    ○ 3 4 5 2 20 ⇒ 1 0 0
    ○ 3 4 5 1 1 1 1 ⇒ 26
    ○ 3 4 5 1 2 3 2 ⇒ 57
    ○ 3 4 5 1 2 0 0 ⇒ 40
    ○ 3 4 5 2 59 ⇒ 2 3 4
*/

int main(){
    int depth, rows, cols;
    cin >> depth >> rows >> cols;

    int choice;
    cin >> choice;
    if(choice==1){
        int d,r,c;
        cin >> d >> r >> c;
        cout << d * rows * cols + r * cols + c;
    }
    else if(choice==2){
        int idx;
        cin >> idx;
        int d = idx / (rows * cols);
        idx-= d * rows * cols; // remove depth iterations
        int r = idx/cols;      // then we have just two position
        int c = idx%cols;
        //c = idx - r * cols;
        cout << d << " " << r << " " << c;

        //(Generalization) As shown this logic can be extended to as many dimensions as we have.
        //STEPS
        //1- calculate the first Dimension then remove it.
        //2- calculate the next then remove it.
        // and so on until you reach the last one.
    }

    return 0;
}

