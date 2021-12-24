#include <iostream>
using namespace std;

/*
● Read integer N (< 1000) then N read numbers each is either 0 or 1.
● Find the longest sub-array with number of zeros = numbers of ones
    ○ You can easily implement it using 3 loops
    ○ Or with little thinking using 2 loops (even with no extra arrays)
    ○ Hard: You can implement it without any nested loops
● Inputs ⇒ outputs
    ○ 7 1 0 0 0 1 1 1 ⇒ 6 (e.g. 100011 or 000111)
    ○ 19 1 0 0 0 0 0 1 0 1 1 0 1 0 0 0 0 0 0 1 ⇒ 8 (e.g. 00101101)
● Reduction
    ○ How may this problem be reduced to another problem: longest sub-array of zero sum?
*/

int main(){
    int arr[1000],n ,sz=0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int cnt=0;

    for(int i=n-1; i>0; i--){
        if(i%2==0){
            //cout << i << " ";
            for(int j=0; j<i; j++){
                for(int k=j; k<n; k++)
                    cout << arr[k] << ' ';
                cout << '\n';
            }
            cout << '\n';
        }
    }
    //cout << cnt;

    //cout << sz+1;


    return 0;
}
