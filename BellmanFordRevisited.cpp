#include<bits/stdc++.h>
using namespace std;

struct edge{
    int u,v;
    long long w;
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<edge> edges(m);
    for(int i=0;i<m;i++){
        cin>>edges[i].u>>edges[i].v>>edges[i].w;
    }
    for(int i=0;i<m;i++){
        edges[i].w *= -1;
    }
    vector<long long> distance(n,LLONG_MAX);
    int source;
    cin>>source;
    distance[source]=0;
    for(int i=1;i<=n-1;i++){
        for(auto &e :edges){
            int u=e.u;
            int v=e.v;
            long long w=e.w;
            if(distance[u] != LLONG_MAX && distance[u] + w < distance[v]){
                distance[v] = distance[u] + w;
            }
        }
    }
    bool cycles= false;
    for(auto &e : edges){
        int u=e.u;
        int v = e.v;
        long long w =e.w;
        if(distance[u] != LLONG_MAX && distance[u] + w <distance[v]){
            cycles=true;
            break;
        }
    }

    if(cycles){
        cout<<"-1"<<endl;
    }
    else{
        cout<<-1*distance[n]<<endl;
    }
    return 0;
}