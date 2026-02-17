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
    vector<int> answer(n);
    answer[0]=1;
    for(int i=1;i<n;i++){
        answer[i]=answer[i-1]*nums[i-1];
    }
    int right=1;
    for(int i=n-1;i>=0;i--){
        answer[i]=right*answer[i];
        right=right*nums[i];
    }
    
    for(int i=0;i<n;i++){
        cout<<answer[i]<<" ";
    }
    
    return 0;
}


/*Given an integer array nums, 
return an array answer such that answer[i] 
is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.*/





// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n;
//     cin>>n;
//     vector<int> nums(n);
//     for(int i=0;i<n;i++){
//         cin>>nums[i];
//     }
//     vector<int> answer(n),left(n),right(n);
//     left[0]=1;
//     for(int i=1;i<n;i++){
//         left[i]=left[i-1]*nums[i-1];
//     }
//     right[n-1]=1;
//     for(int i=n-2;i>=0;i--){
//         right[i]=right[i+1]*nums[i+1];
//     }
//     for(int i=0;i<n;i++){
//         answer[i]=left[i]*right[i];
//     }
    
//     for(int i=0;i<n;i++){
//         cout<<answer[i]<<" ";
//     }
    
//     return 0;
// }