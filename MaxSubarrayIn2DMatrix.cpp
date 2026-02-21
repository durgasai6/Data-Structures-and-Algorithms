#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    int maxsum=INT_MIN;

    for(int top=0;top<n;top++){
        vector<int> temp(m,0);
        for(int bottom=top;bottom<n;bottom++){
            for(int column=0;column<m;column++){
                temp[column]+=matrix[bottom][column];
            }
            int current=temp[0];
            int maxi=temp[0];
            for(int i=1;i<m;i++){
                current=max(temp[i],current+temp[i]);
                maxi=max(maxi,current);
            }
            maxsum=max(maxsum,maxi);   
        }
    }
    cout<<maxsum<<endl;
    return 0;
}
/*Maximum Subarray in 2D Matrix

Given a 2D integer matrix, find the submatrix with the largest sum and return its sum.*/