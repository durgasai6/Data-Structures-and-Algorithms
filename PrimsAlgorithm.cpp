#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> matrix(n+1);
    vector<bool> visited(n+1,false);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        matrix[u].push_back({v,w});
        matrix[v].push_back({u,w});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});
    long long mincost=0;

    while(!pq.empty()){
        int weight=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if(visited[node]){
            continue;
        }
        visited[node]=true;
        mincost+=weight;
        for(auto &edge : matrix[node]){
            int next=edge.first;
            int w=edge.second;
            if(!visited[next]){
                pq.push({w,next});
            }
        }
    }
    cout<<mincost<<endl;
    
    return 0;
}