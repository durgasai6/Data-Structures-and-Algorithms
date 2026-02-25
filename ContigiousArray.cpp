#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    unordered_map<int,int> mp;
    mp[0]=-1;
    int zeros=0,ones=0,length=0;
    for(int i=0;i<n;i++){
        if(nums[i]==0){
            zeros++;
        }
        else{
            ones++;
        }
        int temp=zeros-ones;
        if(mp.find(temp)!=mp.end()){
            length=max(length,i-mp[temp]);
        }
        else{
            mp[temp]=i;
        }
    }
    cout<<length<<endl;
    return 0;
}




/*Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

 

Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Example 3:

Input: nums = [0,1,1,1,1,1,0,0,0]
Output: 6
Explanation: [1,1,1,0,0,0] is the longest contiguous subarray with equal number of 0 and 1.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.*/