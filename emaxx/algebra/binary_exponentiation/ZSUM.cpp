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

const int mod = 10000007;
const int maxn = 200000000;

ll binpow(ll a, ll b){
    a = a%mod;
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

    // S(N) + S(N-1) - 2*S(N-2) = n^k + 2*(n-1)^(k-1)
    // P(N) + P(N-1) - 2*P(N-2) = n^n + 2*(n-1)^(n-1)

    while(1){
        ll n,k; cin>>n>>k;
        if(n == 0 and k == 0) break;

        ll S = (binpow(n,k)%mod + 2*binpow(n-1,k)%mod)%mod;
        ll P = (binpow(n,n)%mod + 2*binpow(n-1,n-1)%mod)%mod;
        cout<<(S+P)%mod<<endl;
    }
}