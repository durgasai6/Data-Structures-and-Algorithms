#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;
vector<vector<bool>> visited;
int n,m;

void dfs(int x, int y , bool &valid){
    visited[x][y]=true;

    if(x==0 || y==0 ||x==n-1||y==m-1){
        valid=false;
    }
    bool up=(x>0 && !visited[x-1][y] && grid[x-1][y]==1);
    bool down=(x<n-1 && !visited[x+1][y] && grid[x+1][y]==1);
    bool left=(y>0 && !visited[x][y-1] && grid[x][y-1]==1);
    bool right=(y<n-1 && !visited[x][y+1] && grid[x][y+1]==1);

    if(up){
        dfs(x-1,y,valid);
    }
    if(down){
        dfs(x+1,y,valid);
    }
    if(left){
        dfs(x,y-1,valid);
    }
    if(right){
        dfs(x,y+1,valid);
    }
}



int main(){
    cin>>n>>m;
    grid.resize(n,vector<int>(m,0));
    visited.resize(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }

    int answer=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && !visited[i][j]){
                bool valid=true;
                dfs(i,j,valid);
                if(valid){
                    answer++;
                }
            }
        }
    }
    cout<<answer<<endl;
    return 0;
}


/*This is a beautiful upgrade of the classic islands problem.
Problem Statement
You are given an N × M grid of 0s and 1s.
1 = land
0 = water
Two land cells belong to the same island if they are connected up, down, left, or right.
An island is called valid if none of its cells touch the border of the grid.
Your task is to count the number of valid islands.

Input
First line: N M
Next N lines: M integers (0 or 1)

Output
Number of valid islands*/