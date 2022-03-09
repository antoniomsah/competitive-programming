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

ll gcd(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }

    ll x1,y1;
    ll g = gcd(b,a%b,x1,y1);
    x = y1;
    y = x1 - y1*(a/b);
    return g;
}

void solve(){
    int a,b,c; 
    cin>>a>>b>>c;

    ll x,y;
    ll g = gcd(a,b,x,y);

    if(c%g) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}

int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);

    int t; cin>>t;
    for(int i=1; i<=t; i++){
        cout<<"Case "<<i<<": ";
        solve();
    }
}