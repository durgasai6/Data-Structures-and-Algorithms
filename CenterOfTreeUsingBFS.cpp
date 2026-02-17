#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> previous,dist;

int bfs(int current, int n){
    dist.assign(n+1,-1);
    previous.assign(n+1,-1);
    queue<int> q;
    q.push(current);
    dist[current]=0;
    while(!q.empty()){
        int currentnode=q.front();
        q.pop();
        for(int next:adj[currentnode]){
            if(dist[next]==-1){
                dist[next]=dist[currentnode]+1;
                previous[next]=currentnode;
                q.push(next);
            }
        }
    }
    int farpoint=current;
    for(int i=1;i<=n;i++){
        if(dist[i]>dist[farpoint]){
            farpoint=i;
        }
    }
    return farpoint;
}
int main(){
    int n;
    cin>>n;
    adj.resize(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int temp1=bfs(1,n);
    int temp2=bfs(temp1,n);
    vector<int> path;
    int temp=temp2;
    while(temp!=-1){
        path.push_back(temp);
        temp=previous[temp];
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