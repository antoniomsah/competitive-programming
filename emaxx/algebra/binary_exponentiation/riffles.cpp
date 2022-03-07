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

vector<int> f(vector<int> a, vector<int> b){
    vector<int> res;
    for(int i=0; i<b.size(); i++)
        res.push_back(a[b[i]]);
    return res;
}

int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);

    int T; cin>>T;
    while(T--)
    {
        ll n,k; cin>>n>>k;
        // n is even!

        vector<int> res;
        for(int i=0; i<n; i++) res.push_back(i);

        vector<int> a;
        ll b=k;
        for(int i=0; i<n; i+=2) a.push_back(i);
        for(int i=1; i<n; i+=2) a.push_back(i);

        while(b>0){
            if(b&1) res = f(res,a);
            a = f(a,a);
            b >>= 1;
        }

        for(int r: res) cout<<r+1<<" "; cout<<endl;
    }
}