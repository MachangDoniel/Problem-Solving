#include <iostream>
#include<bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <limits>
#define ll long long
#define ld long double

using namespace std;

ld Log(ld base,ld up){
    return log2(up)/log2(base);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1;
    cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        string s; cin>>s;
        ld base=0;
        if(s=="bit") base=2;
        else if(s=="nat") base=2.718281828459045;
        else base=10;
        vector<ll>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        ld ans=0.0,mn=0.0;
        for(int i=0;i<n;i++){
            if(v[i]!=0) ans+=(v[i]*1.0)*(Log(base,v[i]*1.0));
        }
        cout<<fixed<<setprecision(12)<<(-ans)/100+Log(base,100*1.0)<<endl;
    }
}

// 3
// 3 bit
// 25 25 50
// 7 nat
// 1 2 4 8 16 32 37
// 10 dit
// 10 10 10 10 10 10 10 10 10 10




