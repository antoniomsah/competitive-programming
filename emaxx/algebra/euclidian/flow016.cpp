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

ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

ll lcm (ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int a,b; 
        cin>>a>>b;
        cout<<gcd(a,b)<<" "<<lcm(a,b)<<endl;
    }
}