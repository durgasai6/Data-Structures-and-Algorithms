#include<bits/stdc++.h>
using namespace std;

vector<int> g[100100];
int visited[100100];
vector<int> topo;

void dfs(int node){
    visited[node]=1;
    for(auto v:g[node]){
        if(!visited[v]){
            dfs(v);
        }
    }
    topo.push_back(node);
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    reverse(topo.begin(),topo.end());
    return 0;
}