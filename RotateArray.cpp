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
    k=k%n;
    vector<int> result;
    for(int i=n-k;i<n;i++){
        result.push_back(nums[i]);
    }
    for(int i=0;i<n-k;i++){
        result.push_back(nums[i]);
    }
    for(int i=0;i<n;i++){
        cout<<result[i]<<" ";
    }
    return 0;
}