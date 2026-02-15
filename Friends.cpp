#include<bits/stdc++.h>
using namespace std;
vector<int> parent,sz;

int findparent(int x){
    if(parent[x]==x){
        return x;
    }
    return parent[x]=findparent(parent[x]);
}

void unify(int x ,int y){
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
    int t;
    cin>>t;
    
    while(t--){
        int n,m,x;
        cin>>n>>m>>x;
        parent.resize(n+1);
        sz.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
            sz[i]=1;
        }
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            unify(a,b);
        }
        unordered_map<int,int> compsize;
        for(int i=1;i<=n;i++){
            int parent=findparent(i);
            compsize[parent]++;
        }
        vector<int> sizes;
        for(auto &s : compsize){
            sizes.push_back(s.second);
        }
        vector<int> dp(n+1,0);
        for(int i=0;i<sizes.size();i++){
            for(int capacity=x;capacity>=sizes[i];capacity--){
                dp[capacity]=max(dp[capacity],dp[capacity-sizes[i]]+sizes[i]);
            }
        }
        cout<<dp[x]<<endl;
    }

    return 0;
}



