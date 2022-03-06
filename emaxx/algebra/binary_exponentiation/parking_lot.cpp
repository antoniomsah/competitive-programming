#include <iostream>
#include <bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
#define vi vector<int>

#define pb push_back
#define read(a) for(int &x: a) cin>>x;
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

using namespace std;

ll binpow(ll a, ll b){
    ll res=1;
    while(b>0){
        if(b&1) res = res*a;
        a = a*a;
        b >>= 1;
    }
    return res;
}

int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);

    int n; cin>>n;

    /*
    ll res=0;
    for(int i=1; i<=n-1; i++){
        if(i == n-1 or i == 1) res += binpow(4,n-3)*3;
        else res += binpow(4,n-4)*9; 
    }
    */

   ll a = binpow(4,n-3)*3, b = binpow(4,n-4)*9;
   ll res = 2*a+(max(n-3,0)*b);

    cout<<4*res<<endl;
}