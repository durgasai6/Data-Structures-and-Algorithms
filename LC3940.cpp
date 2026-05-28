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
    unordered_map<int,int> freq;
    vector<int> ans;
    for(int i=0;i<n;i++){
        freq[nums[i]]++;
        if(freq[nums[i]]<=k){
            ans.push_back(nums[i]);
        }
    }
    for(int x:ans){
        cout<<x<<" ";
    }
    return 0;
}








/*You are given a sorted integer array nums and an integer k.

Return an array such that each distinct element appears at most k times, while preserving the relative order of the elements in nums.

Note: If a distinct element appears at least k times, then it must appear exactly k times in the resulting array.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2

Output: [1,1,2,2,3]

Explanation:

Each element can appear at most 2 times.

The element 1 appears 3 times, so only 2 occurrences are kept.
The element 2 appears 2 times, so both occurrences are kept.
The element 3 appears 1 time, so it is kept.
Thus, the resulting array is [1, 1, 2, 2, 3].

Example 2:

Input: nums = [1,2,3], k = 1

Output: [1,2,3]

Explanation:

All elements are distinct and already appear at most once, so the array remains unchanged.

 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
nums is sorted in non-decreasing order.
1 <= k <= nums.length*/