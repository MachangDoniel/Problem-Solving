#include <bits/stdc++.h> 
using namespace std;

// int fact[]

int fact(int n,int p){
    if(n==0 || n==1) return 1;
    return (n*fact(n-1,p))%p;
}

int boringFactorials(int n, int p)
{
    return fact(n,p);
}
int main(){
    int t; cin>>t;
    while(t--){
        int n,p; cin>>n>>p;
        cout<<": "<<endl;
        cout<<boringFactorials(n,p)<<endl;
    }
}