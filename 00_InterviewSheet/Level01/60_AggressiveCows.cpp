#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/// https://www.spoj.com/problems/AGGRCOW/

int BSLow(vector<int> v, int val){
    int st = 0;
    int en = (int)v.size()-1;

    while(st<=en){
        int mid = st + (en - st)/2;

        if(v[mid]<=val)
            st = mid + 1;
        else if(v[mid]>val)
            en = mid - 1;
    }
    if(st>=(int)v.size())
        return 0;
    return 1;
}


int main(){

    int T,N,C;
    cin >> T;

    while(T--){
        cin >> N >> C;
        vector<int> v(N);
        for(int i=0; i<N; i++)
            cin >> v[i];

        sort(v.begin(), v.end());
        int gap = *v.rbegin() - *v.begin();

        while(true){
            int c = 1;
            for(int i=1; i<C; i++){
                if(BSLow(v, v[gap]))
                    c++;
            }

            if(c==C){
                cout << gap;
                break;
            }
            gap--;
        }
    }



}
