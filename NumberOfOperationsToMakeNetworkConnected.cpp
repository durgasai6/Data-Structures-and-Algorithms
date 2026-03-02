#include<bits/stdc++.h>
using namespace std;

vector<int> parent, sz;

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
    if(sz[xparent]<sz[yparent]){
        swap(xparent,yparent);
    }
    parent[yparent]=xparent;
    sz[xparent]+=sz[yparent];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    parent.resize(n);
    sz.resize(n);
    for(int i=0;i<n;i++){
        parent[i]=i;
        sz[i]=1;
    }
    vector<vector<int>> connections;
    int a,b;
    while(cin>>a>>b){
        connections.push_back({a,b});
    }
    int m=connections.size();

    if(m<n-1){
        cout<<-1<<endl;
        return 0;
    }

    for(int i=0;i<m;i++){
        unify(connections[i][0],connections[i][1]);
    }
    int answer=-1;
    for(int i=0;i<n;i++){
        if(findparent(i)==i){
            answer++;
        }
    }
    cout<<answer<<endl;

    return 0;
}





/*There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

 

Example 1:


Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
Example 2:


Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2
Example 3:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.
 

Constraints:

1 <= n <= 105
1 <= connections.length <= min(n * (n - 1) / 2, 105)
connections[i].length == 2
0 <= ai, bi < n
ai != bi
There are no repeated connections.
No two computers are connected by more than one cable.*/