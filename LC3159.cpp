#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,x;
    cin>>n>>m>>x;
    vector<int> nums(n), queries(m);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    } 
    for(int i=0;i<m;i++){
        cin>>queries[i];
    }
    vector<int> occurances, ans;
    for(int i=0;i<n;i++){
        if(nums[i]==x){
            occurances.push_back(i);
        }
    }
    for(int i=0;i<m;i++){
        if(queries[i]>occurances.size()){
            ans.push_back(-1);
        }
        else{
            ans.push_back(occurances[queries[i]-1]);
        }
    }
    for(int k:ans){
        cout<<k<<" ";
    }
    return 0;
}











/*You are given an integer array nums, an integer array queries, and an integer x.

For each queries[i], you need to find the index of the queries[i]th occurrence of x in the nums array. If there are fewer than queries[i] occurrences of x, the answer should be -1 for that query.

Return an integer array answer containing the answers to all queries.

 

Example 1:

Input: nums = [1,3,1,7], queries = [1,3,2,4], x = 1

Output: [0,-1,2,-1]

Explanation:

For the 1st query, the first occurrence of 1 is at index 0.
For the 2nd query, there are only two occurrences of 1 in nums, so the answer is -1.
For the 3rd query, the second occurrence of 1 is at index 2.
For the 4th query, there are only two occurrences of 1 in nums, so the answer is -1.
Example 2:

Input: nums = [1,2,3], queries = [10], x = 5

Output: [-1]

Explanation:

For the 1st query, 5 doesn't exist in nums, so the answer is -1.
 

Constraints:

1 <= nums.length, queries.length <= 105
1 <= queries[i] <= 105
1 <= nums[i], x <= 104*/