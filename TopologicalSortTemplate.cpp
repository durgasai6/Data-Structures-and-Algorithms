#include<bits/stdc++.h>
using namespace std;

vector<int> topo(vector<vector<int>>& edges){
    int n=edges.size();
    vector<vector<int>> adj(n);
    vector<int> indegree(n,0);
    for(auto &e:edges){
        int u=e[0];
        int v=e[1];

        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<int> q;

    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int> ans;

    while(!q.empty()){
        int curr=q.front();
        q.pop();
        ans.push_back(curr);

        for(int neigh:adj[curr]){
            indegree[neigh]--;
            if(indegree[neigh]==0){
                q.push(neigh);
            }
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<vector<int>> edges(n,vector<int>(2));
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>edges[i][j];
        }
    }
    vector<int> ans=topo(edges);

   
    for(int x:ans){
        cout<<x<<" ";
    }
    
    return 0;
}