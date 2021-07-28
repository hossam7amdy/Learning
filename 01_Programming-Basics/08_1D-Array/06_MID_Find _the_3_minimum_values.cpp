#include <iostream>
using namespace std;

/*
● Read integer N (>= 3), then read N integers. Find the 3 lowest numbers.
    ○ Don’t change the array content
    ○ Don’t iterate on the array more than once

● Input ⇒ Output
○ 5 4 1 3 10 8 ⇒ 1 3 4
○ 3 7 9 -2 ⇒ -2 7 9
*/

main(){
    const int MAX = 200;
    int arr[MAX];

    int n;
    cin >> n;

    for(int i=0; i<n; i++)
        cin >> arr[i];

    int mn1, mn2, mn3;
    mn1 = mn2 = mn3 = 200;

    if(n==3)
        mn1 = arr[0], mn2 = arr[1], mn3 = arr[2];
    else{
    for(int i=0; i<n; i++){
        if(mn1 > arr[i])
            mn1 = arr[i++];
        if(i<n && mn2 > arr[i])
            mn2 = arr[i++];
        if(i<n && mn3 > arr[i])
            mn3 = arr[i++];
        }
    }

    cout << mn1 << ' ' << mn2 << ' ' << mn3 << endl;



    return 0;
}
