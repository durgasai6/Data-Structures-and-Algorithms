#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> neighbours;
vector<bool> visited;
int far;
int diameter;
int n;

void dfs(int node, int depth){
    visited[node]=true;

    if(depth>diameter){
        diameter=depth;
        far=node;
    }
    for(int next:neighbours[node]){
        if(!visited[next]){
            dfs(next,depth+1);
        }
    }

}

int main(){

    cin>>n;
    
    neighbours.resize(n+1);
    visited.assign(n+1,false);
    for (int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        neighbours[a].push_back(b);
        neighbours[b].push_back(a);
    }
    diameter=0;
    dfs(1,0);

    visited.assign(n+1,false);
    diameter=0;
    dfs(far,0);
    cout<<diameter<<endl;
    return 0;
}