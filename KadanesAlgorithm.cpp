#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int maxsum=0,current=0;
    for(int i=0;i<n;i++){
        current=max(nums[i],current+nums[i]);
        maxsum=max(maxsum,current);
    }
    cout<<maxsum<<endl;
    return 0;
}