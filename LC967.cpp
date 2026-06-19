#include<bits/stdc++.h>
using namespace std;

vector<int> ans;

void solve(int num, int len, int k, int n){
    if(len==n){
        ans.push_back(num);
        return;
    }
    int last=num%10;
    
    if(last+k<=9){
        solve(num*10 + last+k,len+1,k,n);
    }
    if(k!=0 && last-k>=0){
        solve(num*10 +(last-k),len+1,k,n);
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=9;i++){
        solve(i,1,k,n);
    }
    for(int x:ans){
        cout<<x<<" ";
    }

    return 0;
}











/*Given two integers n and k, return an array of all the integers of length n where the difference between every two consecutive digits is k. You may return the answer in any order.

Note that the integers should not have leading zeros. Integers as 02 and 043 are not allowed.

 

Example 1:

Input: n = 3, k = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
Example 2:

Input: n = 2, k = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 

Constraints:

2 <= n <= 9
0 <= k <= 9*/