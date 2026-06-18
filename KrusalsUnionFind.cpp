#include<bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<long long> sz;

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
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({wt,u,v});
    }

    sort(edges.begin(),edges.end());

    parent.resize(n);
    sz.resize(n);
    for(int i=0;i<n;i++){
        parent[i]=i;
        sz[i]=1;
    }

    long long mstcost=0;
    int edgesused=0;
    for(auto &edge:edges){
        int wt=edge[0];
        int u=edge[1];
        int v=edge[2];
        if(findparent(u)!=findparent(v)){
            unite(u,v);
            mstcost+=wt;
            edgesused++;
        }
    }

    if(edgesused!=n-1){
        cout<<"MST doesnt exist"<<endl;
        return 0;
    }
    cout<<mstcost<<endl;

    return 0;   
}













/*You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

 

Example 1:


Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation: 

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
Example 2:

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18
 

Constraints:

1 <= points.length <= 1000
-106 <= xi, yi <= 106
All pairs (xi, yi) are distinct.*/