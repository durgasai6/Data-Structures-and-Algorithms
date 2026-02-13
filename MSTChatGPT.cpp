#include<bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<long long> size;

int findparent(int x){
    if(parent[x]==x){
        return x;
    }
    return parent[x]=findparent(parent[x]);
}

void unify(int x, int y){
    int xparent=findparent(x);
    int yparent=findparent(y);
    if(xparent==yparent){
        return;
    }
    if(size[xparent]<size[yparent]){
        swap(xparent,yparent);
    }
    parent[yparent]=xparent;
    size[xparent]+=size[yparent];
}

int main(){
    int n,m;
    cin>>n>>m;
    parent.resize(n+1);
    size.resize(n+1);
    for(int i=1;i<=n;i++){
        parent[i]=i;
        size[i]=1;
    }
    vector<vector<long long>> edge;
    for(int i=0;i<m;i++){
        int u,v;
        long long w;
        cin>>u>>v>>w;
        edge.push_back({w,u,v});
    }
    sort(edge.begin(),edge.end());
    long long answer=0,edges=0;
    for(auto e:edge){
        long long weight=e[0];
        int u=e[1];
        int v=e[2];
        if(findparent(v)!=findparent(u)){
            unify(u,v);
            answer+=weight;
            edges++;
        }
    }
    if(edges!=n-1){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        cout<<answer<<endl;
    }
    return 0;
}

/*You are given N cities and M roads.
Each road: u v weight Find: 
Minimum cost required to connect all cities. 
If not possible, print IMPOSSIBLE.*/