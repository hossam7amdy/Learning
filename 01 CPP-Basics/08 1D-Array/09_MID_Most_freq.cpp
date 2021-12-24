#include <iostream>
using namespace std;

/*
● Read an Integer N, then read N <= 200 integers. Find the value that repeated
the most number of times.
    ○ Each integer is -500 <= value <= 270
● Example for array: 7 -1 2 -1 3 -1 5 5
    ○ -1 repeated 3 times: the largest
● Don’t use nested loops
*/

int main()
{
    //A Little bit different of the optimal one.
    int freq_arr[800]={0};
    int n, num, freq;

    cin >> n;
    for(int i=0; i<n; i++){
        int value;
        cin >> value;
        if(value<0)
            freq_arr[270-value]++;
        else
            freq_arr[value]++;
        }

    for(int i=0; i<800; i++){
        if(!i)
            num = freq_arr[i], freq = i;
        else{
            if(num<freq_arr[i])
                num = freq_arr[i], freq = i;
        }
    }

    if(freq<=270)
        cout << freq << " repeated " << num << " times .\n";
    else
        cout << 270 - freq << " repeated " << num << " times.\n";

    return 0;
}
