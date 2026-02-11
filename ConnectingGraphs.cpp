#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> matrix;
vector<bool> visited;

void dfs(int node){
    visited[node]=true;
    for(int neighbour: matrix[node]){
        if(visited[neighbour]==false){
            dfs(neighbour);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    matrix.resize(n+1);
    visited.resize(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        matrix[u].push_back(v);
        matrix[v].push_back(u);
    }
    int components=0;
    for(int i=1;i<=n;i++){
        if(visited[i]==false){
            components++;
            dfs(i);
        }
    }
    cout<<components-1<<endl;
    return 0;
}

/*You are given an undirected graph with N nodes and M edges. 
Task Find the minimum number of edges required to add so 
that the graph becomes connected. 

Constraints 
1 ≤ N ≤ 10⁵ 
0 ≤ M ≤ 10⁵*/