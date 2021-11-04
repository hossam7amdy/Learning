#include<iostream>
#include<vector>
using namespace std;

/// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1552

int BSFind(vector<int> v, int val){
    int st = 0;
    int en = v.size()-1;

    while(st <= en){

        int mid = st + (en - st)/2;

        if(v[mid]==val)
            return mid;
        else if(v[mid]<val)
            st = mid + 1;
        else
            en = mid - 1;
    }
    return -1;
}

int BSFirst(vector<int> v, int val){
    int st = 0;
    int en = v.size()-1;

    while(st<en){
        int mid = st + (en - st)/2;

        if(v[mid]>val)
            en = mid - 1;
        else if(v[mid]<val)
            st = mid + 1;
        else
            en = mid;
    }
    return en;
}

int BSLast(vector<int> v, int val){
    int st = 0;
    int en = v.size()-1;

    while(st<en){

        int mid = st + (en - st + 1)/2;

        if(v[mid]>val)
            en = mid - 1;
        else if(v[mid]<val)
            st = mid + 1;
        else
            st = mid;
    }
    return st;
}

int lo(vector<int> v, int val){
    int st = 0;
    int en = (int)v.size()-1;

    while(st<=en){
        int mid = st + (en - st)/2;

        //cout << mid << " ";
        if(v[mid]>=val)
            en = mid - 1;
        else
            st = mid + 1;
    }
    if(en<0)
        return -1;

    return v[en];
}

int hi(vector<int> v, int val){
    int st = 0;
    int en = (int)v.size()-1;

    while(st<=en){
        int mid = st + (en - st)/2;

        if(v[mid]<=val)
            st = mid + 1;
        else
            en = mid - 1;
    }
    if(st>=(int)v.size())
        return  -1;

    return v[st];
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("c.in", "rt", stdin);
	freopen(".txt", "wt", stdout);
#endif

    int Q,N;
    cin >> N;
    vector<int> v(N);

    for(int i=0; i<N; i++)
        cin >> v[i];

    cin >> Q;
    while(Q--){
        int val;
        cin >> val;

        int L = lo(v,val);
        int H = hi(v,val);

        if(L==-1)
            cout << "X";
        else
            cout << L;
        if(H==-1)
            cout << " X";
        else
            cout << " " << H;
        cout << endl;
    }

    return 0;
}
