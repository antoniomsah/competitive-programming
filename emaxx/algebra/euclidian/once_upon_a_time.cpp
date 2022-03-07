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

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);

    while(1){
        ll n,m,a,k;
        cin>>n>>m>>a>>k;
        if(n == 0 and m == 0 and a == 0 and k == 0) break;

        // elderly man starts at the next iteration (first iteration is the approach)
        k = k+a;

        if(n > k){swap(n,k); swap(m,a);}

        if((n < k and m == 0) or (k < n and a == 0)){
            cout<<"Impossible"<<endl; continue;
        }

        ll x,y,g = gcd(a,m,x,y);
        ll c = k-n;
        if(c%g) { cout<<"Impossible"<<endl; continue; }

        x *= c/g;
        y *= c/g;

        // needs to find the maximum 'x' that is less than 0 and valid
        // 'x' is valid <=> c = m*(x+a/g) + a(y-m/g)
        if(x>0){
            ll s = ceil(double(x*g)/m);
            x -= s*m/g; 
            y += s*a/g;
        }
        else{
            ll s = x*g/m; // = floor(x*g/m)
            x -= s*m/g; 
            y += s*a/g; 
        }
        cout<<n+y*m<<endl;
    }
}