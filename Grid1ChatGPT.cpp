#include<bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>> &pref, int n, int m, int k, int side){
    for(int i=0;i+side<=n;i++){
        for(int j=0;j+side<=m;j++){
            int count= pref[i+side][j+side]-pref[i][j+side] -pref[i+side][j] + pref[i][j];
            if(count<=k){
                return true;
            }
            
        }
        
    }
    return false;
}

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> grid(n,vector<int>(m,0));
    vector<vector<int>> pref(n+1,vector<int>(m+1,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            pref[i][j]= grid[i-1][j-1] +pref[i-1][j]+pref[i][j-1] - pref[i-1][j-1];
        }
    }

    int l=0,r=min(n,m);
    int answer=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(pref,n,m,k,mid)){
            answer=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout<<answer<<endl;
    return 0;
}



/*You are given a grid of size N × M containing only 0s and 1s.
You are also given an integer K.
A square subgrid is called almost-uniform if the number of 1s inside it is at most K.
Your task is to find the maximum possible side length of any almost-uniform square subgrid.

Input
First line: integers N M K
Next N lines: M integers (0 or 1)

Output
Print one integer — the maximum side length*/