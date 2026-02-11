#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> neighbours;
vector<bool> visited;
vector<int> component;
vector<int> componentsize;

void dfs(int current, int number){
    visited[current]=true;
    component[current]=number;
    componentsize[number]++;
    for(int neighbour:neighbours[current]){
        if(!visited[neighbour]){
            dfs(neighbour,number);
        }
    }
}


int main(){
    int n,m,q;
    cin>>n>>m>>q;
    visited.resize(n+1,false);
    component.resize(n+1);
    neighbours.resize(n+1);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        neighbours[u].push_back(v);
        neighbours[v].push_back(u);
    }
    int number=0;
    for(int i=0;i<=n;i++){
        if(!visited[i]){
            componentsize.push_back(0);
            dfs(i,number);
            number++;
        }
    }

    while(q--){
        int choice;
        cin>>choice;
        if(choice==1){
            int x;
            cin>>x;
            cout<<componentsize[component[x]]<<endl;
        }
        else{
            int x,y;
            cin>>x>>y;
            if(component[x]==component[y]){
                cout<<"yes"<<endl;
            }
            else{
                cout<<"no"<<endl;
            }
        }
    }
    return 0;
}