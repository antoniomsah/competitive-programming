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

    ll B,P,M;
    while(cin>>B){
        cin>>P>>M;

        ll res=1;
        while(P>0){
            if(P&1) res = res*B%M;
            B = B*B%M;
            P >>= 1;
        }
        cout<<res<<endl;
    }
}