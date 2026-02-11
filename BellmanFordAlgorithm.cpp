#include<bits/stdc++.h>
using namespace std;

struct edge{
    int u,v,w;
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<edge> edges(m);
    for(int i=0;i<m;i++){
        cin>>edges[i].u>>edges[i].v>>edges[i].w;
    }
    int source;
    cin>>source;
    vector<long long> distance(n,LLONG_MAX);
    distance[source]=0;

    for(int i=1;i<=n-1;i++){
        for(auto &e:edges){
            int u=e.u;
            int v=e.v;
            int w=e.w;
            if(distance[u] != LLONG_MAX && distance[u]+w<distance[v]){
                distance[v] = distance[u]+w;
            }
        }
    }
    bool negativecyles=false;
    for(auto &e : edges){
        int u=e.u;
        int v=e.v;
        int w= e.w;
        if(distance[u]!= LLONG_MAX && distance[u] + w <distance[v]){
            negativecyles=true;
            break;
        }
    }
    if(negativecyles){
        cout<<"Negative Cycle is detected"<<endl;
    }
    else{
        for(int i=0;i<n;i++){
            if(distance[i] == LLONG_MAX){
                cout<<"infinity"<<endl;
            }
            else{
                cout<<distance[i]<<" ";
        }
    }
            cout<<endl;
    }
    return 0;
}