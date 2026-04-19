#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> temp(n);
    for(int i=0;i<n;i++){
        cin>>temp[i];
    }
    stack<int> st;
    vector<int> ans(n,0);
    for(int i=0;i<n;i++){
        while(!st.empty() && temp[i]>temp[st.top()]){
            int last=st.top();
            st.pop();
            ans[last]=i-last;
        }
        st.push(i);
    }
    for(int x:ans){
        cout<<x<<" ";
    }
    return 0;
}













/*Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
 

Constraints:

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100*/