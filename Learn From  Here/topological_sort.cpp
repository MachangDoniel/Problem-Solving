#include<bits/stdc++.h>
using namespace std;


    
// MyTask

void topolocial_sort(){
     int node,edge; cin>>node>>edge;
    vector<vector<int>>adjList(node+1);
    for(int i=0;i<edge;i++){
        int edge1,edge2; cin>>edge1>>edge2;
        adjList[edge1].push_back(edge2);
    }
    vector<int> inDegree(node+1,0);
        for(int i=1;i<node+1;i++){
            for(int j=0;j<adjList[i].size();j++){
                inDegree[adjList[i][j]]++;
            }                                                
        }
        queue<int>q;
        for(int i=1;i<node+1;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int course=q.front(); // can be completable
            q.pop();
            topo.push_back(course);
            // decrease inDegree of the courses that have this course as prerequisite
            for(int i=0;i<adjList[course].size();i++){
                inDegree[adjList[course][i]]--;
                if(inDegree[adjList[course][i]]==0) q.push(adjList[course][i]);
            }
        }
        cout<<"Topolocal Sorting: ";
        for(int i=0;i<topo.size();i++){
            cout<<topo[i]<<" ";
        }
        cout<<endl;
    
}

main(){
    topolocial_sort();
}