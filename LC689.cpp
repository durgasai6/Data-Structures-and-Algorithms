#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    
    vector<int> subarraysum;
    int sum=0;
    for(int i=0;i<k;i++){
        sum+=nums[i];
    }
    subarraysum.push_back(sum);
    for(int i=k;i<n;i++){
        sum+=nums[i];
        sum-=nums[i-k];
        subarraysum.push_back(sum);
    }
    vector<int> left(subarraysum.size());
    int maxidx=0;
    for(int i=0;i<subarraysum.size();i++){
        if(subarraysum[i]>subarraysum[maxidx]){
            maxidx=i;
        }
        left[i]=maxidx;
    }
    vector<int> right(subarraysum.size());
    int maxrightidx=subarraysum.size()-1;
    for(int i=subarraysum.size()-1;i>=0;i--){
        if(subarraysum[i]>=subarraysum[maxrightidx]){
            maxrightidx=i;
        }
        right[i]=maxrightidx;
    }
    vector<int> ans(3);
    int totalmax=INT_MIN;
    for(int j=k;j<subarraysum.size()-k;j++){
        int l=left[j-k];
        int r=right[j+k];
        int total=subarraysum[l]+subarraysum[j]+subarraysum[r];
        if(total>totalmax){
            totalmax=total;
            ans[0]=l;
            ans[1]=j;
            ans[2]=r;
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}







/*Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum sum and return them.

Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.

 

Example 1:

Input: nums = [1,2,1,2,6,7,5,1], k = 2
Output: [0,3,5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
Example 2:

Input: nums = [1,2,1,2,1,2,1,2,1], k = 2
Output: [0,2,4]
 

Constraints:

1 <= nums.length <= 2 * 104
1 <= nums[i] < 216
1 <= k <= floor(nums.length / 3)*/