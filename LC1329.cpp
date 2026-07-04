#include<bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    vector<vector<int>> arrays;

    for(int r=0;r<n;r++){
        int i=r,j=0;
        vector<int> temp;
        while(i<n && j<m){
            temp.push_back(matrix[i][j]);
            i++;
            j++;
        }
        sort(temp.begin(),temp.end());
        arrays.push_back(temp);
    }

    for(int c=1;c<m;c++){
        int i=0,j=c;
        vector<int> temp;

        while(i<n && j<m){
            temp.push_back(matrix[i][j]);
            i++;
            j++;
        }
        sort(temp.begin(),temp.end());
        arrays.push_back(temp);
    }

    int d=0;

    for(int r=0;r<n;r++){
        int i=r,j=0;
        int k=0;

        while(i<n && j<m){
            matrix[i][j]=arrays[d][k++];
            i++;
            j++;
        }
        d++;
    }

    for(int c=1;c<m;c++){
        int i=0,j=c;
        int k=0;

        while(i<n && j<m){
            matrix[i][j]=arrays[d][k++];
            i++;
            j++;
        }
        d++;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    
    return 0;
}







