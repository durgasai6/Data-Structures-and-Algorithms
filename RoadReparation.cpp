#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,long long>>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    priority_queue<pair<long long,int>,vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    vector<bool> visited(n+1);
    long long answer=0,nodes=0;
    pq.push({0,1});

    while(!pq.empty()){
        long long weight=pq.top().first;
        long long node=pq.top().second;
        pq.pop();
        if(visited[node]){
            continue;
        }
        visited[node]=true;
        answer+=weight;
        nodes++;
        for(auto neigh: adj[node]){
            int next=neigh.first;
            long long nextweight=neigh.second;
            if(!visited[next]){
                pq.push({nextweight,next});
            }
        }
    }
    if(nodes!=n){
        cout<<"impossible"<<endl;
    }
    else{
        cout<<answer<<endl;
    }
    return 0;
}

