#include<iostream>
using namespace std;

/*
● Read integer N, then Read Square matrix NxN. Then, print 2 values. The
sum of the lower triangle matrix and the upper triangle.
● Input
    ○ 3
    ○ 8 16 9
    ○ 3 15 27
    ○ 14 25 29
● Output
    ○ 94 (8+15+29+3+25+14)
    ○ 104 (8+15+29+16+27+9)
*/

int main(){
    int const MAX = 100;
    int matrix[MAX][MAX];

    //8 16 9 3 15 27 14 25 29

    int sz, upper=0, lower=0;
    cin >> sz;
    for(int i=0; i<sz; i++){ //computing on the fly
        for(int j=0; j<sz; j++){
            cin >> matrix[i][j];

            if(i>=j)
                lower += matrix[i][j];

            if(i<=j)
                upper += matrix[i][j];
        }
    }
    cout << lower << " " << upper;



    return 0;
}

