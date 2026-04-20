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
    stack<int> st;
    for(int i=0;i<n;i++){
        int num=nums[i];
        while(!st.empty() && st.top()>num){
            num=max(num, st.top());
            st.pop();
        }
        st.push(num);
    }
    cout<<st.size()<<endl;
    return 0;
}











/*You are given an integer array nums. In one operation, you can select a subarray and replace it with a single element equal to its maximum value.

Return the maximum possible size of the array after performing zero or more operations such that the resulting array is non-decreasing.

 

Example 1:

Input: nums = [4,2,5,3,5]

Output: 3

Explanation:

One way to achieve the maximum size is:

Replace subarray nums[1..2] = [2, 5] with 5 → [4, 5, 3, 5].
Replace subarray nums[2..3] = [3, 5] with 5 → [4, 5, 5].
The final array [4, 5, 5] is non-decreasing with size 3.

Example 2:

Input: nums = [1,2,3]

Output: 3

Explanation:

No operation is needed as the array [1,2,3] is already non-decreasing.

 

Constraints:

1 <= nums.length <= 2 * 105
1 <= nums[i] <= 2 * 105*/