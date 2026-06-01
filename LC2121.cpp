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
    unordered_map<int,vector<long long>> mp;
    for(int i=0;i<n;i++){
        mp[nums[i]].push_back(i);
    }

    vector<long long> ans(n);
    for(auto &it:mp){
        vector<long long> pos=it.second;
        int m=it.second.size();
        for(int i=1;i<m;i++){
            it.second[i]+=it.second[i-1];
        }
        for(int i=0;i<it.second.size();i++){
            long long curr=pos[i];
            long long leftcount=i,rightcount=m-i-1;
            long long leftsum= (i==0 ? 0 : it.second[i-1]);
            long long rightsum= it.second[m-1]-it.second[i];

            long long left=leftcount*curr - leftsum;
            long long right=rightsum-rightcount*curr;
            ans[curr]=left+right;

        }
    }
    for(long long x:ans){
        cout<<x<<" ";
    }
    
    return 0;
}









/*You are given a 0-indexed array of n integers arr.

The interval between two elements in arr is defined as the absolute difference between their indices. More formally, the interval between arr[i] and arr[j] is |i - j|.

Return an array intervals of length n where intervals[i] is the sum of intervals between arr[i] and each element in arr with the same value as arr[i].

Note: |x| is the absolute value of x.

 

Example 1:

Input: arr = [2,1,3,1,2,3,3]
Output: [4,2,7,2,4,4,5]
Explanation:
- Index 0: Another 2 is found at index 4. |0 - 4| = 4
- Index 1: Another 1 is found at index 3. |1 - 3| = 2
- Index 2: Two more 3s are found at indices 5 and 6. |2 - 5| + |2 - 6| = 7
- Index 3: Another 1 is found at index 1. |3 - 1| = 2
- Index 4: Another 2 is found at index 0. |4 - 0| = 4
- Index 5: Two more 3s are found at indices 2 and 6. |5 - 2| + |5 - 6| = 4
- Index 6: Two more 3s are found at indices 2 and 5. |6 - 2| + |6 - 5| = 5
Example 2:

Input: arr = [10,5,10,10]
Output: [5,0,3,4]
Explanation:
- Index 0: Two more 10s are found at indices 2 and 3. |0 - 2| + |0 - 3| = 5
- Index 1: There is only one 5 in the array, so its sum of intervals to identical elements is 0.
- Index 2: Two more 10s are found at indices 0 and 3. |2 - 0| + |2 - 3| = 3
- Index 3: Two more 10s are found at indices 0 and 2. |3 - 0| + |3 - 2| = 4
 

Constraints:

n == arr.length
1 <= n <= 105
1 <= arr[i] <= 105*/