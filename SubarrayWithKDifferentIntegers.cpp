#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        
        int atmostk=0,atmostkminus1=0;
        unordered_map<int,int> freq;
        int left=0;
        for(int right=0;right<n;right++){
            freq[nums[right]]++;
            while(freq.size()>k){
                freq[nums[left]]--;
                if(freq[nums[left]]==0){
                    freq.erase(nums[left]);
                }
                left++;
            }
            atmostk+=(right-left+1);
        }
        unordered_map<int,int> freq1;
        int left1=0;
        for(int right=0;right<n;right++){
            freq1[nums[right]]++;
            while(freq1.size()>k-1){
                freq1[nums[left1]]--;
                if(freq1[nums[left1]]==0){
                    freq1.erase(nums[left1]);
                }
                left1++;
            }
            atmostkminus1+=(right-left1+1);
        }
        cout<<(atmostk-atmostkminus1)<<endl;
    }
    return 0;
}