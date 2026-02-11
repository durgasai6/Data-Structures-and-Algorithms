#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> colour;
bool bipartite=true;

void dfs(int node){
    for(int v :adj[node]){
        if(colour[v]==-1){
            colour[v] = 1-colour[node];
            dfs(v);
            if(!bipartite){
                return;
            }
        }
        else if(colour[v] == colour[node]){
            bipartite=false;
            return;
        }
    }
}




int main(){
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    colour.assign(n+1,-1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(colour[i]==-1){
            colour[i]=0;
            dfs(i);
            if(!bipartite){
                break;
            }
        }
    }
    if(bipartite){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<< endl;
    }
    
    return 0;
}


/*You are given an undirected graph with N nodes and M edges.
Your task is to determine whether the graph is bipartite.
A graph is called bipartite if you can color every node using only 2 colors such that no two adjacent nodes have the same color.

Input Format
First line: two integers N and M
Next M lines: two integers u v representing an edge between u and v

Output Format
Print "YES" if the graph is bipartite
Print "NO" otherwise*/