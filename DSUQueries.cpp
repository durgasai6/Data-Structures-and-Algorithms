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
    int xparent= findparent(x);
    int yparent= findparent(y);
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
    int n,q;
    cin>>n>>q;
    parent.resize(n+1);
    size.resize(n+1);
    for(int i=1;i<=n;i++){
        parent[i]=i;
        size[i]=1;
    }
    while(q--){
        int choice,u,v;
        cin>>choice>>u>>v;
        if(choice==1){
            unify(u,v);
        }
        else{
            if(findparent(v)==findparent(u)){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}

/*You are given N nodes and Q queries: 
Queries are of two types: 
1 u v → add an edge between u and 
v 2 u v → check if u and v are connected 
Print YES or NO for type 2 queries.*/