#include<bits/stdc++.h>
using namespace std;


int main()
{
    int a,b; cin>>a>>b;
    auto add = [](int a, int b) -> int { return a+b; };
    auto sub = [](int a, int b) -> int { return a-b; };
    auto mul = [&](int a, int b) -> int { return a*b; };
    auto div = [](int a, int b) -> int { return a/b; };
    cout<<add(a,b)<<endl;
    cout<<sub(a,b)<<endl;
}