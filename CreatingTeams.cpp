#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> team;
bool valid=true;

void dfs(int node){
    for(int next : adj[node]){
        if(team[next]==-1){
            team[next] = 1- team[node];
            dfs(next);
            if(valid==false){
                return;
            }
        }
        else if(team[next]==team[node]){
            valid=false;
            return;
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    team.assign(n+1,-1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(team[i]==-1){
            team[i]=0;
            dfs(i);
            if(valid==false){
                break;
            }
        }
    }
    if(valid==false){
        cout<<"no"<<endl;
    }
    else{
        cout<<"yes"<<endl;
    }
    return 0;
}