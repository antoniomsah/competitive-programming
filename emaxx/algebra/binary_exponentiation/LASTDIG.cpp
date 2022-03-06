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
        if(b&1) res = res*a%10;
        a = a*a%10;
        b >>= 1;
    }
    return res;
}

int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        a = a%10;
        cout<<binpow(a,b)<<endl;
    }

}