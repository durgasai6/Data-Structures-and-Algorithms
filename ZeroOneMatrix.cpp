#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    vector<vector<int>> answer(n,vector<int>(m,-55));
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0){
                q.push({i,j});
                answer[i][j]=0;
            }
        }
    }
    while(!q.empty()){
        int x=q.front().first;
        int y = q.front().second;
        q.pop();
        if(x<n-1 && answer[x+1][y]==-55){
            answer[x+1][y]=answer[x][y]+1;
            q.push({x+1,y});
        }
        if(y<m-1 && answer[x][y+1]==-55){
            answer[x][y+1]=answer[x][y]+1;
            q.push({x,y+1});
        }
        if(x>0 && answer[x-1][y]==-55){
            answer[x-1][y]=answer[x][y]+1;
            q.push({x-1,y});
        }
        if(y>0 && answer[x][y-1]==-55){
            answer[x][y-1]=answer[x][y]+1;
            q.push({x,y-1});
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<answer[i][j]<< " ";

        }
        cout<<endl;
    }
    return 0;
}





/*Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.

 

Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.*/