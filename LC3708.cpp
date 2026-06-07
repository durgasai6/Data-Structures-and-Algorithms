#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<long long> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    else if(n==2){
        cout<<2<<endl;
        return 0;
    }
    int left=0,right=2;
    int ans=2;
    while(right<n){
        if(nums[right]==nums[right-1]+nums[right-2]){
            ans=max(ans,right-left+1);
        }
        else{
            left=right-1;
        }
        right++;
        
    }

    cout<<ans<<endl;   
    return 0;
}











/*You are given an array of positive integers nums.

A Fibonacci array is a contiguous sequence whose third and subsequent terms each equal the sum of the two preceding terms.

Return the length of the longest Fibonacci subarray in nums.

Note: Subarrays of length 1 or 2 are always Fibonacci.

 

Example 1:

Input: nums = [1,1,1,1,2,3,5,1]

Output: 5

Explanation:

The longest Fibonacci subarray is nums[2..6] = [1, 1, 2, 3, 5].

[1, 1, 2, 3, 5] is Fibonacci because 1 + 1 = 2, 1 + 2 = 3, and 2 + 3 = 5.

Example 2:

Input: nums = [5,2,7,9,16]

Output: 5

Explanation:

The longest Fibonacci subarray is nums[0..4] = [5, 2, 7, 9, 16].

[5, 2, 7, 9, 16] is Fibonacci because 5 + 2 = 7, 2 + 7 = 9, and 7 + 9 = 16.

Example 3:

Input: nums = [1000000000,1000000000,1000000000]

Output: 2

Explanation:

The longest Fibonacci subarray is nums[1..2] = [1000000000, 1000000000].

[1000000000, 1000000000] is Fibonacci because its length is 2.

 

Constraints:

3 <= nums.length <= 105
1 <= nums[i] <= 109*/