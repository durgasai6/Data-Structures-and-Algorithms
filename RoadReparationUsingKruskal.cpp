#include<bits/stdc++.h>
using namespace std;
vector<int> parent,size;


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
        long long u,v,w;
        cin>>u>>v>>w;
        edge.push_back({w,u,v});
    }
    sort(edge.begin(),edge.end());
    long long answer=0,edges=0;
    for(auto e : edge){
        long long weight=e[0];
        long long u=e[1];
        long long v=e[2];
        if(findparent(u)!=findparent(v)){
            unify(u,v);
            answer+=weight;
            edges++;
        }
    }
    if(edges!=n-1){
        cout<<"impossible"<<endl;
    }
    else{
        cout<<answer<<endl;
    }
    return 0;
}