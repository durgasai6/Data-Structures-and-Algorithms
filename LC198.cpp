#include<bits/stdc++.h>
using namespace std;

int solve(int idx, vector<int>& nums, vector<int>& dp){
    if(idx>=nums.size()){
        return 0;
    }
    if(dp[idx]!=-1){
        return dp[idx];
    }

    int rob=nums[idx]+solve(idx+2,nums,dp);
    int dont=solve(idx+1,nums,dp);

    return dp[idx]=max(rob,dont);
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
    vector<int> dp(n,-1);
    cout<<solve(0,nums,dp);
    return 0;
}













/*You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400*/