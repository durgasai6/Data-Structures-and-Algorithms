#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> neighbours;
vector<bool> visited;

int dfs(int current){
    visited[current]=true;
    int count =1;
    for(int neighbour:neighbours[current]){
        if(!visited[neighbour]){
            count+=dfs(neighbour);
        }
    }
    return count;
}


int main(){
    int n,m;
    cin>>n>>m;
    neighbours.resize(n+1);
    visited.resize(n+1,false);
    vector<long long> compsize;

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        neighbours[a].push_back(b);
        neighbours[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            compsize.push_back(dfs(i));
        }
    }
    long long answer=0,temp=0;
    for(long long c: compsize){
        answer+=temp*c;
        temp+=c;
    }
    cout<<answer<<endl;
    return 0;
}