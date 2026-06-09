#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
vector<int> curr;

void dfs(int i,vector<int>& nums){
    if(i==nums.size()){
        ans.push_back(curr);
        return;
    }
    curr.push_back(nums[i]);
    dfs(i+1,nums);
    curr.pop_back();
    dfs(i+1,nums);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    dfs(0,nums);
    for(int i=0;i<n;i++){
        int s=ans[i].size();
        for(int j=0;j<s;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}





















/*Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
 
*/