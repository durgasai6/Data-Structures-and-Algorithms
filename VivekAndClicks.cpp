#include<bits/stdc++.h>
using namespace std;

vector<int> parent,sz;

int findparent(int x){
    if(parent[x]==x){
        return x;
    }
    return parent[x]=findparent(parent[x]);
}

void unify(int x,int y){
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

    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>> board(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }
    
    parent.resize(n*m);
    sz.resize(n*m);
    for(int i=0;i<n*m;i++){
        parent[i]=i;
        sz[i]=1;
    }
    int whites=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==1){
                whites++;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==1){
                int currentcell=i*m+j;

                if(j+1<m && board[i][j+1]==1){
                    int rightcell=i*m+j+1;
                    unify(currentcell,rightcell);
                }
                if(i+1<n && board[i+1][j]==1){
                    int downceel=(i+1)*m +j;
                    unify(downceel,currentcell);
                }
            }
        }
    }
    vector<bool> black(n*m,false);

    while(q--){
        int r,c;
        cin>>r>>c;
        r--;
        c--;
        if(board[r][c]==1){
            int currentcell=r*m+c;
            int par=findparent(currentcell);
            if(!black[par]){
                whites-=sz[par];
                black[par]=true;
            }
        }
        cout<<whites<<endl;
    }

    return 0;
}