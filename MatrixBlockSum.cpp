#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> matrix(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    vector<vector<int>> prefix(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            prefix[i][j]=matrix[i-1][j-1]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
        }
    }
    vector<vector<int>> answer(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int r1=max(0,i-k)+1,r2=min(n-1,i+k)+1,c1=max(0,j-k)+1,c2=min(m-1,j+k)+1;
            answer[i][j]=prefix[r2][c2] - prefix[r1-1][c2] - prefix[r2][c1-1] + prefix[r1-1][c1-1];


        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<answer[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}