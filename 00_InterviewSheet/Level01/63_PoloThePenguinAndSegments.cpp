#include<iostream>
using namespace std;

/// https://codeforces.com/contest/289/problem/A

int main(){
	int n, k;

	cin>>n>>k;

	int covered = 0;
	for(int i=0; i<n; i++){
        int st, en;
        cin >> st >> en;

        covered += (en-st+1);
	}
	covered%=k;

	if(covered!=0)
        covered = k - covered;

    cout << covered;

    return 0;
}
