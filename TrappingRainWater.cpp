#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> height(n);
    for(int i=0;i<n;i++){
        cin>>height[i];
    }
    int left=0,right=n-1,lhighest=0,rhighest=0,answer=0;

    while(left<right){
        if(height[left]<height[right]){
            if(height[left]>=lhighest){
                lhighest=height[left];
            }
            else{
                answer+=lhighest-height[left];
            }
            left++;
        }
        else{
            if(height[right]>=rhighest){
                rhighest=height[right];
            }
            else{
                answer+=rhighest-height[right];
            }
            right--;
        }
    }
    cout<<answer<<endl;

    return 0;
}