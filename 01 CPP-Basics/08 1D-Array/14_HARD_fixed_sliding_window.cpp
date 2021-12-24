#include <iostream>
using namespace std;

/*
● Read Integers K and N, (where K <= N). then read N < 200 integers.
● Find sub-array (consecutive numbers) of K elements that has maximum sum
● Input k=3 n=7 ( 1 0 3 -4 2 -6 9 )
    ○ Let’s list all sub-arrays of length 3
    ○ 1 0 3 ⇒ sum = 4
    ○ 0 3 -4 ⇒ sum = -1
    ○ 3 -4 2 ⇒ sum = 1
    ○ -4 2 -6 ⇒ sum = -8
    ○ 2 -6 9 ⇒ sum = 5
● Output: 4 6 5 (Sub-array from indices 4 to 6 has maximum sum of 5)
● Can you do it without nested loops? There are 2 ways.
*/

main(){
    int arr[200], k,n, sum, mx=0, idx;

    cin >> k >> n;
    for(int i=0; i<n; i++){

        if(i<k){
        cin >> arr[i];
        mx += arr[i];
        idx = k;
        continue;
        }
        else if(i == k)
            sum = mx;

        cin >> arr[i];
        sum = sum - arr[i-k] + arr[i];
        if(mx < sum){
            mx = sum;
            idx = i;
        }
    }

    cout << idx-k+1 << " " << idx << " " << mx;

    return 0;
}
