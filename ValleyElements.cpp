#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    } 
    vector<long long> valley;
    int count=0;
    for(int i=1;i<n-1;i++){
        if(nums[i]<nums[i-1] && nums[i]<nums[i+1]){
            count++;
            valley.push_back(nums[i]);
        }
    }

    cout<<count<<endl;
    for(int i=0;i<valley.size();i++){
        cout<<valley[i]<<" ";
    }
    cout<<endl;
    return 0;
}