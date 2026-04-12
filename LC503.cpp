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
    vector<int> ans(n,-1);

    for(int i=2*n-1;i>=0;i--){
        while(!st.empty()&& st.top()<=nums[i%n]){
            st.pop();
        }
        if(i<n){
            if(!st.empty()){
                ans[i]=st.top();
            }
        }
        st.push(nums[i%n]);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}