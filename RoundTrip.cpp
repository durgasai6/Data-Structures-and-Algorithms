#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> neighbours;
vector<bool> visited;
bool cycle=false;

void dfs(int current, int previous){
    visited[current]=true;
    for(int neighbour:neighbours[current]){
        if(!visited[neighbour]){
            dfs(neighbour,current);
        }
        else if(neighbour != previous){
            cycle=true;
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    neighbours.resize(n+1);
    visited.resize(n+1,false);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        neighbours[a].push_back(b);
        neighbours[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i,-1);
            if(cycle){
                cout<<"yes"<<endl;
            }
            else{
                cout<<"no"<<endl;
            }
        }
    }
    return 0;
}