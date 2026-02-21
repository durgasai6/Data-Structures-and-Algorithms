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
    int mini=nums[0];
    int maxi=nums[0];
    int answer=nums[0];
    for(int i=1;i<n;i++){
        if(nums[i]<0){
            swap(maxi,mini);
        }
        maxi=max(nums[i],maxi*nums[i]);
        mini=min(nums[i],mini*nums[i]);
        answer=max(answer,maxi);
    }
    cout<<answer<<endl;

    return 0;
}