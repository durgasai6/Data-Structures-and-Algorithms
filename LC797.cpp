#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;

vector<vector<int>> ans;

void dfs(int node, vector<int>& current, int n){
    current.push_back(node);
    if(node==n-1){
        ans.push_back(current);
    }else{
        for(int neigh:adj[node]){
            dfs(neigh,current,n);
        }
    }
    current.pop_back();
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;

    adj.resize(n);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int> res;
    dfs(0,res,n);
    for(auto &it:ans){
        for(int x:it){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}















/*Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

 

Example 1:


Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Example 2:


Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
 

Constraints:

n == graph.length
2 <= n <= 15
0 <= graph[i][j] < n
graph[i][j] != i (i.e., there will be no self-loops).
All the elements of graph[i] are unique.
The input graph is guaranteed to be a DAG.*/