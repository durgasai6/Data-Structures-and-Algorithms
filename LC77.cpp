#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
vector<int> temp;

void solve(vector<vector<int>>& ans, int start, int n, int k){
    
    if(temp.size()==k){
        ans.push_back(temp);
        return;
    }
    if(start>n){
        return;
    }
    temp.push_back(start);
    solve(ans, start+1, n, k);
    temp.pop_back();
    solve(ans,start+1,n,k);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;

    solve(ans, 1,n,k);
    int m=ans.size();
    for(int i=0;i<m;i++){
        for(int j=0;j<k;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}












/*Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.

 

Example 1:

Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
Example 2:

Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.
 

Constraints:

1 <= n <= 20
1 <= k <= n*/