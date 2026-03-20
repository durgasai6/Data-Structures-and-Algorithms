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
    vector<int> flips;
    for(int i=n;i>=1;i--){
        int curr=0;
        while(nums[curr]!=i){
            curr++;
        }
        if(curr==i-1){
            continue;
        }
        if(curr!=0){
            reverse(nums.begin(),nums.begin()+curr+1);
            flips.push_back(curr+1);
        }
        reverse(nums.begin(),nums.begin()+i);
        flips.push_back(i);
    }
    for(int i=0;i<flips.size();i++){
        cout<<flips[i]<<" ";
    }
    return 0;
}