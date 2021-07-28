#include <iostream>
using namespace std;

/*
Read integer N ( <= 900), followed by reading N integers (0 <= value <= 500)
● Print the unique list of the numbers, but preserve the given order
● Input: 13 1 5 5 2 5 7 2 3 3 3 5 2 7
● Output: 1 5 2 7 3
    ○ Observe: input is not sorted list
    ○ Observe: output preserves the original order: e.g. 5 appears before 2
● Don’t use nested loops
*/

main(){
    const int MAX = 200;
    int arr[MAX]={1, 5, 5, 2, 5, 7, 2, 3, 3, 3, 5, 2, 7, 500, 0, 0, 0, 6, 6, 1, 2, 3, 9, 8, 7, 4, 5, 6, 3, 2, 1,1},n;

    // not the optimal solution.

    n = 32;
    int freq[501] = {0};
    int not_sorted[n]={0};

    for(int i=0; i<n; i++){
        freq[arr[i]]++;
    }




    for(int i=0; i<501; i++){
        if(freq[i]>0){
            for(int j=0; j<n; j++){
                if(i==arr[j]){
                    not_sorted[j] = i;
                    break;
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        if(not_sorted[i]!=0)
            cout << not_sorted[i] << " ";
    }


    return 0;
}
