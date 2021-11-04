#include<bits/stdc++.h>
using namespace std;

/// https://codeforces.com/contest/476/problem/B

int c1 = 0, c2 = 0, c3 = 0, c = 0;

void dfs(int s1,int x){

	if(s1==0){
		if(x==c1)
            c++;
		return;
	}

	dfs(s1-1,x+1);
	dfs(s1-1,x-1);

}

int main(){



    string s1,s2;
    cin >> s1 >> s2;

    int ints[] {1,-1,0};

    for(int i=0; i<(int)s1.size(); ++i){
        c1 += ints[string("+-").find(s1[i])];
        c2 += ints[string("+-?").find(s2[i])];

        c3 += (ints[string("+-?").find(s2[i])]==0);
    }

    if(!c3)
        c1==c2 ? cout << 1.000000000000 : cout << 0.000000000000;
    else{
        dfs(c3,c2);

        cout << setprecision(12) << fixed;
        cout << c / pow(2,c3);
    }



    return 0;
}
