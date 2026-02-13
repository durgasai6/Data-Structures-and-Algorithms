#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> indeg(n+1,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    vector<int> topo;
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(int next: adj[node]){
            indeg[next]--;
            if(indeg[next]==0){
                q.push(next);
            }
        }
    }
    if(topo.size()==n){
        for(int t : topo){
            cout<<t<<" ";
        }
    }
    else{
        cout<<"Impossible"<<endl;
    }
    return 0;
}


/*You are given N courses labeled 1 to N and M prerequisite relations.
Each relation u v means:
You must complete course u before taking course v.

Determine:
If it is possible to complete all courses.
If yes, print one valid order.
If not, print IMPOSSIBLE.*/