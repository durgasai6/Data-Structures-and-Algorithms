#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> dist,previous;

void dfs(int node, int prev, int depth){
    previous[node]=prev;
    dist[node]=depth;
    for(int next:adj[node]){
        if(next!=prev){
            dfs(next,node,depth+1);
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    adj.resize(n+1);
    
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dist.resize(n+1);
    previous.resize(n+1);
    dfs(1,-1,0);
    int temp1=1;
    for(int i=1;i<=n;i++){
        if(dist[i]>dist[temp1]){
            temp1=i;
        }
    }
    dfs(temp1,-1,0);
    int temp2=temp1;
    for(int i=1;i<=n;i++){
        if(dist[i]>dist[temp2]){
            temp2=i;
        }
    }
    vector<int> path;
    int temp3=temp2;
    while(temp3!=-1){
        path.push_back(temp3);
        temp3=previous[temp3];
    }
    int length=path.size();
    if(length%2==0){
        cout<<-1<<endl;
    }
    else{
        cout<<path[length/2]<<endl;
    }
    return 0;
}