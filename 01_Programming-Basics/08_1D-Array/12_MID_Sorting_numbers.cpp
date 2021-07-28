#include <iostream>
using namespace std;

/*
Read integer N ( <= 900), followed by reading N integers (0 <= value <= 500)
● Print the sorted list of the numbers
● Input: 13 1 5 5 2 5 7 2 3 3 3 5 2 7
● Output: 1 2 2 2 3 3 3 5 5 5 5 7 7
● Give your most efficient trial
    ○ You don’t need to google how to sort numbers
    ○ Hint: max value in the array is 500
*/

main(){
    const int MAX = 501;
    int arr[MAX]={0},n;

    cin >> n;

    // 1 5 5 2 5 7 2 3 3 3 5 2 7 500 0 0 0 6 6 1 2 3 9 8 7 4 5 6 3 2 1 1

    for(int i=0; i<n; i++){
        int value;
        cin >> value;
        arr[value]++;
    }

    for(int i=0; i<501; i++){
        while(arr[i]--)
            cout << i << ' ';
    }




    return 0;
}
