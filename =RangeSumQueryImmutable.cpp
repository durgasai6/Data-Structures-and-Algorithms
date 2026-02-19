#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int rows,cols,t;
    cin>>t>>rows>>cols;
    vector<vector<int>> grid(rows,vector<int>(cols,0));
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>> pref(rows+1,vector<int>(cols+1,0));
    for(int i=1;i<=rows;i++){
        for(int j=1;j<=cols;j++){
            pref[i][j]+=grid[i-1][j-1]+pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1];
        }
    }
    while(t--){
        int row,col;
        cin>>row>>col;
        cout<<pref[row][col]<<endl;
    }
    return 0;
}