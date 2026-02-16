#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<long long> pref(n+1,0);
    for(int i=1;i<=n;i++){
        pref[i]=nums[i-1]+pref[i-1];
    }
    long long answer=0;
    unordered_map<long long, int> freq;
    freq[0]=1;
    for(int i=0;i<=n;i++){
        if(freq.count(pref[i]-k)){
            answer+=freq[pref[i]-k];
        }
        freq[pref[i]]++;
    }
    cout<<answer<<endl;
    return 0;
}

/*Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107*/