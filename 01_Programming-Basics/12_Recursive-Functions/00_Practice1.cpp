#include<iostream>
using namespace std;

/*
print
*
**
***
****
*****
*/

void print_stars(int num){
    if(num==0)
        return;
    print_stars(num - 1); // if we moved it below the loop result will reversed. WHY?

    for(int i=0; i<num; i++)
        cout << "*";
    cout << "\n";
}

int main(){
    print_stars(5);

    return 0;
}
