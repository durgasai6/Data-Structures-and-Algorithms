#include<bits/stdc++.h>
using namespace std;



int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back({v,0});
        adj[v].push_back({u,1});
    }
    int maxi=1e9;
    vector<int> distance(n+1,maxi);
    deque<int> dq;
    distance[1]=0;
    dq.push_front(1);
    while(!dq.empty()){
        int node=dq.front();
        dq.pop_front();
        for(auto &edge : adj[node]){
            int next = edge.first;
            int weight = edge.second;
            if(distance[node]+weight < distance[next]){
                distance[next]=distance[node] + weight;
                if(weight==0){
                    dq.push_front(next);
                }
                else{
                    dq.push_back(next);
                }
            }
        }
    }
    if(distance[n]==maxi){
        cout<<-1<<endl;
    }
    else{
        cout<<distance[n]<<endl;
    }
    return 0;
}

/*You are given a directed graph with N nodes and M edges. 
You are allowed to reverse any edge (change direction) at a cost of 1 per reversal. 
Your task is: Find the minimum number of edges to reverse so that there exists a path from node 1 to node N. 
If it's impossible, print -1.*/