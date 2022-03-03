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

int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);

    // 'c' datasets
    int c; cin>>c;
    while(c--)
    {
        // calculate (x^y)%mod;
        ll x,y,mod;
        cin>>x>>y>>mod;

        ll res=1;
        while(y > 0){
            if(y&1) res = res*x%mod;
            x = x*x%mod;
            y >>= 1;
        }
        cout<<res<<endl;
    }
}