#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int k;
string s;
vector<vector<int>>levels;

int sToi(string s){
    int ans=0;
    for(int i=s.size()-1,mul=1;i>=0;i--,mul*=10){
        ans+=mul*(s[i]-'0');
    }
    return ans;
}

void extractTree(int level,string str){
    cout<<str<<endl;
    if(str.size()==0 || str=="()") return;
    string node,lst,rst;
    bool flag=true,flag1=true;
    int count=0;
    for(int i=1;i<int(str.size()-1);i++){ // ignoring 1st '(' and last ')' brackets
        if(flag){
            if(str[i]!='(') node+=str[i];   // node value
            else flag=false;
        }
        if(!flag){
            if(str[i]=='(') count++;
            else if(str[i]==')') count--;
            
            if(flag1) lst+=str[i];
            else rst+=str[i];
            
            if(count==0) flag1=false;
        }
    }
    cout<<sToi(node)<<" "<<lst<<" "<<rst<<endl;
    levels[level].push_back(sToi(node));
    if(lst.size()!=2) extractTree(level+1,lst);
    if(rst.size()!=2) extractTree(level+1,rst);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    cin>>k;
    cin>>s;
    levels.resize(k+1);
    extractTree(0,s);
    int sum=0;
    // for(int i=0;i<levels[k].size();i++){
    //     sum+=levels[k][i];
    // }
    cout<<"ok"<<endl;
    cout<<sum<<endl;
    return 0;
}
