#include<bits/stdc++.h>
using namespace std;


// MyTask
// concept of bigmod
/*
(a.b)%m = ((a%m).(b%m))%m
*/
int bigmod(int a,int p,int m){
    if(p == 0) return 1;
    int q = bigmod(a, p/2, m);
    if(p % 2 == 0) return (q*q) % m;
    return (q*((q*a) % m)) % m;
}

int main()
{
    int base, power, mod; cin>>base>>power>>mod;
    cout<<(bigmod(base,power,mod)+mod)%mod<<endl;
}