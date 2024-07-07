#include<bits/stdc++.h>
using namespace std;


bool isValid(int y,int x,int n,int m){
    return y>=0 && y<n && x>=0 && x<m;
}
void print(queue<pair<int,int>>q){
    cout<<"q: ";
    while(!q.empty()){
        cout<<q.front().first<<","<<q.front().second<<" ";
        q.pop();
    }
    cout<<endl;
}

string bfs(vector<vector<string>>&vv,int start_y,int start_x,int n,int m){
    string res="";
    queue<pair<int,int>>q;
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    // q.push({start_y,start_x});
    visited[start_y][start_x]=true;
    if(isValid(start_y,start_x+1,n,m)){ // right
        q.push({start_y,start_x+1});
    }
    if(isValid(start_y+1,start_x,n,m)){ // down
        q.push({start_y+1,start_x});
    }
    if(isValid(start_y,start_x-1,n,m)){ // left
        q.push({start_y,start_x-1});
    }
    if(isValid(start_y-1,start_x,n,m)){ // up
        q.push({start_y-1,start_x});
    }
    while(!q.empty()){
        // print(q);
        int y=q.front().first,x=q.front().second;
        q.pop();
        if(visited[y][x]) continue;
        visited[y][x]=true;
        
        // cout<<":"<<vv[y][x]<<" "<<y<<" "<<x<<endl;
        
        if(vv[y][x][0]>='A' && vv[y][x][0]<='Z'){
            res+=vv[y][x];
        }
        if(vv[y][x]=="═"){
            if(isValid(y,x+1,n,m) && !visited[y][x+1]){
                q.push({y,x+1});
                // visited[y][x+1]=true;
            }
            if(isValid(y,x-1,n,m) && !visited[y][x-1]){
                q.push({y,x-1});
                // visited[y][x-1]=true;
            }
        }
        else if(vv[y][x]=="║"){
            if(isValid(y+1,x,n,m) && !visited[y+1][x]){
                q.push({y+1,x});
                // visited[y+1][x]=true;
            }
            if(isValid(y-1,x,n,m) && !visited[y-1][x]){
                q.push({y-1,x});
                // visited[y-1][x]=true;
            }
        }
        else if(vv[y][x]=="╔"){
            if(isValid(y,x+1,n,m) && !visited[y][x+1]){
                q.push({y,x+1});
                // visited[y][x+1]=true;
            }
            if(isValid(y+1,x,n,m) && !visited[y+1][x]){
                q.push({y+1,x});
                // visited[y+1][x]=true;
            }
        }
        else if(vv[y][x]=="╗"){
            if(isValid(y,x-1,n,m) && !visited[y][x-1]){
                q.push({y,x-1});
                // visited[y][x-1]=true;
            }
            if(isValid(y+1,x,n,m) && !visited[y+1][x]){
                q.push({y+1,x});
                // visited[y+1][x]=true;
            }
        }
        else if(vv[y][x]=="╚"){
            if(isValid(y,x+1,n,m) && !visited[y][x+1]){
                q.push({y,x+1});
                // visited[y][x+1]=true;
            }
            if(isValid(y-1,x,n,m) && !visited[y-1][x]){
                q.push({y-1,x});
                // visited[y-1][x]=true;
            }
        }
        else if(vv[y][x]=="╝"){
            if(isValid(y,x-1,n,m) && !visited[y][x-1]){
                q.push({y,x-1});
                // visited[y][x-1]=true;
            }
            if(isValid(y-1,x,n,m) && !visited[y-1][x]){
                q.push({y-1,x});
                // visited[y-1][x]=true;
            }
        }
        else if(vv[y][x]=="╠"){
            if(isValid(y,x+1,n,m) && !visited[y][x+1]){
                q.push({y,x+1});
                // visited[y][x+1]=true;
            }
            if(isValid(y+1,x,n,m) && !visited[y+1][x]){
                q.push({y+1,x});
                // visited[y+1][x]=true;
            }
            if(isValid(y-1,x,n,m) && !visited[y-1][x]){
                q.push({y-1,x});
                // visited[y-1][x]=true;
            }
        }
        else if(vv[y][x]=="╣"){
            if(isValid(y,x-1,n,m) && !visited[y][x-1]){
                q.push({y,x-1});
                // visited[y][x-1]=true;
            }
            if(isValid(y+1,x,n,m) && !visited[y+1][x]){
                q.push({y+1,x});
                // visited[y+1][x]=true;
            }
            if(isValid(y-1,x,n,m) && !visited[y-1][x]){
                q.push({y-1,x});
                // visited[y-1][x]=true;
            }
        }
        else if(vv[y][x]=="╦"){
            if(isValid(y,x+1,n,m) && !visited[y][x+1]){
                q.push({y,x+1});
                // visited[y][x+1]=true;
            }
            if(isValid(y,x-1,n,m) && !visited[y][x-1]){
                q.push({y,x-1});
                // visited[y][x-1]=true;
            }
            if(isValid(y+1,x,n,m) && !visited[y+1][x]){
                q.push({y+1,x});
                // visited[y+1][x]=true;
            }
        }
        else if(vv[y][x]=="╩"){
            if(isValid(y,x+1,n,m) && !visited[y][x+1]){
                q.push({y,x+1});
                // visited[y][x+1]=true;
            }
            if(isValid(y,x-1,n,m) && !visited[y][x-1]){
                q.push({y,x-1});
                // visited[y][x-1]=true;
            }
            if(isValid(y-1,x,n,m) && !visited[y-1][x]){
                q.push({y-1,x});
                // visited[y-1][x]=true;
            }
        }
    }
    return res;
}

string submit(const string& input_file) {
    ifstream file(input_file);
    string ch;
    int x,y,n=0,m=0;
    vector<pair<string,pair<int,int>>>v;
    while (file>>ch>>x>>y) {
        // cout<<ch<<" "<<x<<" "<<y<<endl;
        m=max(m,x);
        n=max(n,y);
        v.push_back({ch,{x,y}});
    }
    // cout<<n<<" "<<m<<endl;
    vector<vector<string>>vv(n+1,vector<string>(m+1,"_"));
    int start_x,start_y;
    for(int i=0;i<v.size();i++){
        int index_x=v[i].second.first,index_y=n-v[i].second.second;
        vv[index_y][index_x]=v[i].first;
        if(v[i].first=="*"){
            start_x=index_x;
            start_y=index_y;
        }
        // cout<<v[i].first<<" "<<index_x<<" "<<index_y<<endl;
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         cout<<vv[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    string res=bfs(vv,start_y,start_x,n+1,m+1);
    // cout<<res<<endl;
    file.close();
    return res;
}

int main() {
    string res=submit("io.txt");
    cout<<res<<endl;
    return 0;
}
