// Finding min and the occurance of the min of a range in an array using segment tree

#include<bits/stdc++.h>
using namespace std;


const int INF=1e9;
int n;
vector<int>tree;

void build(vector<int>&a,int index,int left,int right){
    if(left==right){
        tree[index]=a[left];
    }
    else{
        int mid=(left+right)/2;
        build(a,2*index+1,left,mid);
        build(a,2*index+2,mid+1,right);
        tree[index]=min(tree[2*index+1],tree[2*index+2]);
    }
}

int get_min(int index,int left,int right,int l,int r){
    if(l>r) return INF;
    if(l==left && r==right) return tree[index];
    int mid=(left+right)/2;
    return min(
        get_min(2*index+1,left,mid,l,min(r,mid)),
        get_min(2*index+2,mid+1,right,max(l,mid+1),r));
}

int get_min(int l,int r){
    return get_min(0,0,n-1,l,r);
}

int main(){
    cin>>n;
    tree.resize(4*n);
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    build(a,0,0,n-1);
    // for(int i=0;i<4*n;i++){
    //     cout<<tree[i]<<" ";
    // }
    // cout<<endl;
    cout<<get_min(0,3)<<endl;
    cout<<get_min(2,4)<<endl;
}