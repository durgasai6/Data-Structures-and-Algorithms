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

    vector<long long> pref(n);
    pref[0]=nums[0];
    for(int i=1;i<n;i++){
        pref[i]=pref[i-1]+nums[i];
    }
    long long answer=0;
    unordered_map<int,int> mp;
    mp[0]=1;
    
    for(int i=0;i<n;i++){
        int remainder=((pref[i]%k)+k)%k;
        if(mp.count(remainder)){
            answer+=mp[remainder];
        }
        mp[remainder]++;
    }
    cout<<answer<<endl;
    return 0;
}





/*Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
Example 2:

Input: nums = [5], k = 9
Output: 0
 

Constraints:

1 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
2 <= k <= 104*/