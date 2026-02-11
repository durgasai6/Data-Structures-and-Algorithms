#include<bits/stdc++.h>
using namespace std;
vector<int> parent,sz;

int find(int node){
    if(parent[node]==node){
        return node;
    }
    return parent[node]=find(parent[node]);
}

void unify(int x, int y){
    int xparent=find(x);
    int yparent=find(y);
    if(xparent==yparent){
        return;
    }
    if(sz[xparent]<sz[yparent]){
        swap(xparent,yparent);
    }
    parent[yparent]=xparent;
    sz[xparent]+=sz[yparent];
}

int main(){
    int n,m;
    cin>>n>>m;
    parent.resize(n+1);
    sz.resize(n+1);
    for(int i=1;i<=n;i++){
        parent[i]=i;
        sz[i]=1;
    }
    int components=n;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        if(find(u) != find(v)){
            unify(u,v);
            components--;
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