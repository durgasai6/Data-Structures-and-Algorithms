#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int x){
    visited[x] = true;
    for(int adjacent:adj[x]){
        if(!visited[adjacent]){
            dfs(adjacent);
        }
    }
}


int main(){
    int n,m;
    cin>>n>>m;
    

    adj.resize(n+1);
    visited.resize(n+1,false);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int components=0;
    for(int place =1;place<=n;place++){
        if(!visited[place]){
            dfs(place);
            components++;
        }
    }
    cout<<components-1<<endl;
    return 0;
}