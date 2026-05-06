#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int k=1;
    vector<vector<int>> ans(n,vector<int>(n));
    int top=0,left=0,right=n-1,bottom=n-1;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            ans[top][i]=k;
            k++;
        }
        top++;

        for(int i=top;i<=bottom;i++){
            ans[i][right]=k;
            k++;
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans[bottom][i]=k;
                k++;
            }
        }
        bottom--;
        if(right>=left){
            for(int i=bottom;i>=top;i--){
                ans[i][left]=k;
                k++;
            }
        }
        left++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}














/*Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

 

Example 1:


Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:

Input: n = 1
Output: [[1]]
 

Constraints:

1 <= n <= 20*/