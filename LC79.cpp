#include<bits/stdc++.h>
using namespace std;
int n,m;
bool dfs(vector<vector<char>>& grid, string word, int i, int j, int idx){
    if(idx==word.length()){
        return true;
    }
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!=word[idx]){
        return false;
    }
    char curr=word[idx];
    grid[i][j]='#';
    bool check=false;
    check =dfs(grid,word,i+1,j,idx+1) || dfs(grid,word,i-1,j,idx+1) || dfs(grid,word,i,j-1,idx+1) || dfs(grid,word,i,j+1,idx+1);

    grid[i][j]=curr;
    return check;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    string word;
    cin>>word;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dfs(grid,word,i,j,0)){
                cout<<"true"<<endl;
                return 0;
            }
        }
    }
    cout<<"false"<<endl;
    return 0;
}










/*Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.*/