// Finding sum of a range in an array using segment tree

#include<bits/stdc++.h>
using namespace std;

const int N=20005;

// size of the aray
int n;
// this segment tree is a 0-based tree, where root is in 0th index
// child of index is in 2*index+1 and 2*index+2
vector<int>tree;

// a[], the array i want to convert into segment tree
// index, the index of the current node of segment tree
// left,right, the range of the array a[]
void build(vector<int>&a,int index,int left,int right){
    if(left==right){     // leaf node
        tree[index]=a[left];
    }
    else{
        int mid=(left+right)/2;
        build(a,2*index+1,left,mid);
        build(a,2*index+2,mid+1,right);
        tree[index]=tree[2*index+1]+tree[2*index+2];
    }
}
// index is the current node of the segment tree
// left,right is the range of the array a[]
// l,r is the range of the array a[] which i want to find the sum of
int sum(int index,int left,int right,int l,int r){
    if(l>r) return 0;
    if(l==left && r==right) return tree[index];
    int mid=(left+right)/2;
    return sum(2*index+1,left,mid,l,min(r,mid))+sum(2*index+2,mid+1,right,max(l,mid+1),r);
}
// l,r are the range of the array a[] which i want to find the sum of
int sum(int l,int r){
    // starting from the root node (index=0)
    // search in the range 0->n-1 in the segment tree
    // l,r are the range of the array a[] which i want to find the sum of
    return sum(0,0,n-1,l,r);
}

void update(int index,int left,int right,int pos,int value){
    if(left==right) tree[index]=value;
    else{
        int mid=(left+right)/2;
        if(pos<=mid) update(2*index+1,left,mid,pos,value);
        else update(2*index+2,mid+1,right,pos,value);
        tree[index]=tree[2*index+1]+tree[2*index+2];
    }
}

void print(vector<int>&a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    cin>>n;
    vector<int>a(n);
    tree.resize(4*n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    build(a,0,0,n-1);
    // print(a);
    // print(tree);
    cout<<sum(2,3)<<endl;
    // update(0,0,n-1,2,10);
    // print(a);
    // print(tree);
    cout<<sum(2,3)<<endl;
}