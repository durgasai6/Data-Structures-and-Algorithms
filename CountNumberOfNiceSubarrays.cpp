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
    int left=0,odds=0,answer=0;
    for(int right=0;right<n;right++){
        if(nums[right]%2!=0){
            odds++;
        }
        while(odds>k){
            if(nums[left]%2!=0){
                odds--;
            }
            left++;
        }
        answer+=(right-left+1);
    }

    int low=0,odds2=0,answer2=0;
    for(int high=0;high<n;high++){
        if(nums[high]%2!=0){
            odds2++;
        }
        while(odds2>k-1){
            if(nums[left]%2!=0){
                odds2--;
            }
            left++;
        }
        answer2+=(high-low+1);
    }
    cout<<answer-answer2<<endl;
    return 0;
}