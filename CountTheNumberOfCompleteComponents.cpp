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
    parent.resize(n);
    sz.resize(n,1);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    vector<pair<int,int>> edges(m);
    for(int i=0;i<m;i++){
        cin>>edges[i].first>>edges[i].second;
        unite(edges[i].first,edges[i].second);
    }
    vector<int> nodes(n,0), edge(n,0);
    for(int i=0;i<n;i++){
        nodes[(findparent(i))]++;
    }
    for(auto &it:edges){
        edge[findparent(it.first)]++;
    }
    int components=0;
    for(int i=0;i<n;i++){
        if(nodes[i]==0){
            continue;
        }
        int k=nodes[i];
        int e=k*(k-1)/2;
        if(edge[i]==e){
            components++;
        }
    }
    cout<<components<<endl;
    return 0;
}









/*You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.

Return the number of complete connected components of the graph.

A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

A connected component is said to be complete if there exists an edge between every pair of its vertices.

 

Example 1:



Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
Output: 3
Explanation: From the picture above, one can see that all of the components of this graph are complete.
Example 2:



Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
Output: 1
Explanation: The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two vertices. On the other hand, the component containing vertices 3, 4, and 5 is not complete since there is no edge between vertices 4 and 5. Thus, the number of complete components in this graph is 1.
 

Constraints:

1 <= n <= 50
0 <= edges.length <= n * (n - 1) / 2
edges[i].length == 2
0 <= ai, bi <= n - 1
ai != bi
There are no repeated edges.*/