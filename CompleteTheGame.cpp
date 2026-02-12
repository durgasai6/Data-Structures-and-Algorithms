#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> indeg(n+1,0);
    vector<long long> ways(n+1,0);
    ways[1]=1;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    queue<int> q;
    vector<int> topological;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int currentnode=q.front();
        q.pop();
        topological.push_back(currentnode);
        for(int nextnode : adj[currentnode]){
            indeg[nextnode]--;
            if(indeg[nextnode]==0){
                q.push(nextnode);
            }
        }
    }
    for(int n : topological){
        for(int nextnode:adj[n]){
            ways[nextnode]=(ways[nextnode]+ways[n])%mod;
        }
    }
    cout<<ways[n]<<endl;
    return 0;
}