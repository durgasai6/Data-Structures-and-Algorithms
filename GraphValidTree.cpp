#include<bits/stdc++.h>
using namespace std;

vector<int> parent,sz;

int findparent(int x){
    if(parent[x]==x){
        return x;
    }
    return parent[x]=findparent(parent[x]);
}

void unite(int x, int y){
    int xparent=findparent(x);
    int yparent=findparent(y);
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
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    if(m!=n-1){
        cout<<"false"<<endl;
        return 0;
    }
    parent.resize(n);
    sz.resize(n,1);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        if(findparent(v)==findparent(u)){
            cout<<"false"<<endl;
            return 0;
        }
        unite(u,v);
    }
    cout<<true<<endl;
    return 0;
}