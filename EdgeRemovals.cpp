#include<bits/stdc++.h>
using namespace std;
vector<int> parent,sz;

int findparent(int x){
    if(parent[x]==x){
        return x;
    }
    return parent[x]=findparent(parent[x]);
}

bool unify(int x,int y){
    int xparent=findparent(x);
    int yparent=findparent(y);
    if(xparent==yparent){
        return false;
    }
    if(sz[xparent]<sz[yparent]){
        swap(xparent,yparent);
    }
    parent[yparent]=xparent;
    sz[xparent]+=sz[yparent];
    return true;
}


int main(){
    int n,m,q;
    cin>>n>>m>>q;
    parent.resize(n+1);
    sz.resize(n+1);
    vector<pair<int,int>> edges(m+1);
    for(int i=1;i<=m;i++){
        cin>>edges[i].first>>edges[i].second;
    }
    vector<pair<int,int>> queries(q);
    vector<bool> removed(m+1,false);
    for(int i=0;i<q;i++){
        int choice;
        cin>>choice;

        if(choice==1){
            int x;
            cin>>x;
            queries[i]={1,x};
            removed[x]=true;
        }
        else{
            queries[i]={2,0};
        }
    }
    for(int i=1;i<=n;i++){
        parent[i]=i;
        sz[i]=1;
    }
    int components=n;
    for(int i=1;i<=m;i++){
        if(!removed[i]){
            int u=edges[i].first;
            int v=edges[i].second;
            if(unify(u,v)){
                components--;
            }
        }
    }
    vector<int> answer;
    for(int i=q-1;i>=0;i--){
        if(queries[i].first==1){
            int edge=queries[i].second;
            int u=edges[edge].first;
            int v=edges[edge].second;
            if(unify(u,v)){
                components--;
            }
        }
        else{
            answer.push_back(components);
        }
    }
    for(int i=answer.size()-1;i>=0;i--){
        cout<<answer[i]<<endl;
    }
    return 0;
}

