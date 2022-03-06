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

const int mod = int(1e9+7);

ll binpow(ll a, ll b){
    ll res=1;
    while(b>0){
        if(b&1) res = res*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return res;
}

int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);

    

    int t; cin>>t;
    while(t--){
        ll n; cin>>n;

        if(n <= 2){ cout<<max(1LL,n)<<endl; continue; }

        // use powers of 3.
        // if n%3 == 1, answer needs to have a 4 -> 3^m*4
        // if n%3 == 2, answer needs to have a 2 -> 3^m*2

        ll m;
        if(n%3 == 0) m = n/3;
        if(n%3 == 1) m = (n-4)/3;
        if(n%3 == 2) m = (n-2)/3;

        ll res = binpow(3,m);
        if(n%3 == 1) res *= 4;
        if(n%3 == 2) res *= 2;
        cout<<res%mod<<endl;   
    }

}