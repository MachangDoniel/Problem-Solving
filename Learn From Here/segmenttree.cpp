#include<bits/stdc++.h>
using namespace std;

#define int long long
// MyTask

class SegmentTree{
    public:
        int n;
        vector<int>segmentTree,lazyTree;

        SegmentTree(){}
        SegmentTree(int n){ resize(n);}
        void resize(int n){
            this->n=n;
            segmentTree.resize(4*n,0);
            lazyTree.resize(4*n,0);
        }
        void push(int start,int end,int node){
            if(lazyTree[node]){
                // segmentTree[node]=max(lazyTree[node],segmentTree[node]);         // For max queries
                segmentTree[node]=(end-start+1)*lazyTree[node];                     // For sum queries
                if (start!=end){
                    // lazyTree[2*node+1]=max(lazyTree[2*node+1],lazyTree[node]);   // For max queries
                    // lazyTree[2*node+2]=max(lazyTree[2*node+2],lazyTree[node]);;  // For max queries
                    lazyTree[2 * node + 1] += lazyTree[node];                       // For sum queries
                    lazyTree[2 * node + 2] += lazyTree[node];                       // For sum queries
                }
                lazyTree[node]=0;
            }
        }
        int query(int start,int end,int l,int r,int node){
            push(start,end,node);
            if (start>r || end<l) return 0;
            if (start>=l && end<=r) return segmentTree[node];
            int mid=(start+end)/2;
            int q1=query(start,mid,l,r,2*node+1);
            int q2=query(mid+1,end,l,r,2*node+2);
            // return max(q1,q2); // for max
            // return min(q1,q2); // for min
            return q1+q2; // for sum
        }
        void update(int start,int end,int node,int l,int r,int value){
            push(start,end,node);
            if (start>r || end<l) return;
            if (start>=l && end<=r){
                // lazyTree[node]=value;   // For max queries
                lazyTree[node]+=value;  // For sum queries
                push(start,end,node);   
                return;
            }
            // partial case
            int mid=(start+end)/2;
            update(start,mid,2*node+1,l,r,value);
            update(mid+1,end,2*node+2,l,r,value);
            // segmentTree[node]=max(segmentTree[node*2+1],segmentTree[node*2+2]);      // For max queries
            segmentTree[node] = segmentTree[2 * node + 1] + segmentTree[2 * node + 2];  // For sum queries
            return;
        }
        int query(int l,int r){ return query(0,n-1,l,r,0);}
        void update(int l,int r,int x){ update(0,n-1,0,l,r,x);}
};

void print(vector<int>&arr){
    for(int i=0;i<arr.size();i++) cout<<arr[i]<<" ";
    cout<<endl;
}

main(){
    int n; cin>>n;
    SegmentTree st(n);
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    print(st.segmentTree);
    // print(st.lazyTree);
    for(int i=0;i<n;i++){
        st.update(i,i,arr[i]);
        print(st.segmentTree);
        // print(st.lazyTree);
    } 
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cout<<"Query of ("<<i<<","<<j<<") ";
            cout<<st.query(i,j)<<endl;
        }
        cout<<endl;
    }
    st.update(0,2,5);
    print(st.segmentTree);
    print(st.lazyTree);
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cout<<"Query of ("<<i<<","<<j<<") ";
            cout<<st.query(i,j)<<endl;
        }
        cout<<endl;
    }
    cout<<st.query(0,n-1)<<endl;
    return 0;
}