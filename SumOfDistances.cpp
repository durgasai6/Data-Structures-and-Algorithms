#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> neighbours;
vector<long long> comp;
long long n,answer=0;

void dfs(int node, int parent){
    comp[node]=1;
    for(int neigh : neighbours[node]){
        if(neigh==parent){
            continue;
        }
        dfs(neigh,node);
        long long temp = comp[neigh];
        answer+=temp*(n-temp);
        comp[node]+=temp;
    }
}

int main(){
    cin>>n;
    neighbours.resize(n+1);
    comp.resize(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        neighbours[a].push_back(b);
        neighbours[b].push_back(a);
    }
    dfs(1,0);
    cout<<answer<<endl;
    return 0;
}