#include<bits/stdc++.h>
using namespace std;



int findparent(vector<int> &parent,int x ){
    if(parent[x]==x){
        return x;
    }
    return parent[x] = findparent(parent,parent[x]);
}

void unifying(vector<int> &parent, vector<int> &size, int u, int v){
    int uparent,vparent;
    uparent=findparent(parent,u);
    vparent=findparent(parent,v);
    if(uparent==vparent){
        return;
    }
    if(size[uparent]<size[vparent]){
        swap(uparent,vparent);
    }
    parent[vparent]=uparent;
    size[uparent]+=size[vparent];
    
    
}

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<int> parent(n+1),size(n+1);
    for(int i=1;i<=n;i++){
        parent[i]=i;
        size[i]=1;
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        unifying(parent,size,u,v);
    }
    while(q--){
        int choice;
        cin>>choice;
        if(choice==1){
            int x;
            cin>>x;
            int parentnode=findparent(parent,x);
            cout<<size[parentnode]<<endl;
        }
        else{
            int x,y;
            cin>>x>>y;
            if(findparent(parent,x)==findparent(parent,y)){
                cout<<"yes"<<endl;
            }
            else{
                cout<<"no"<<endl;
            }
        }
    }
    return 0;
}