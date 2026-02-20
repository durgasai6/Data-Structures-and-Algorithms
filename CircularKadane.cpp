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
    int maxsum=INT_MIN, currentsum=0,total=0,currentmin=0,minsum=INT_MAX;
    for(int i=0;i<n;i++){
        total+=nums[i];
        currentsum=max(nums[i],currentsum+nums[i]);
        maxsum=max(maxsum, currentsum);

        currentmin=min(nums[i],currentmin+nums[i]);
        minsum=min(currentmin, minsum);
    }
    if(maxsum<0){
        cout<<maxsum<<endl;
    }
    else{
        cout<<max(maxsum, total-minsum)<<endl;;
    }
    return 0;
}