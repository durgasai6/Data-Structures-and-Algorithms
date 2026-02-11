#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<long long> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        if(k==0){
            cout<<0<<endl;
            continue;
        }
        long long subarrays=0;
        int l=0;
        int distinct = 0;
        unordered_map<long long,long long> freq;

        for(int r=0;r<n;r++){
            freq[nums[r]]++;
        


        if(freq[nums[r]]==1){
            distinct++;
        }



        while(distinct >k){
            freq[nums[l]]--;
            if(freq[nums[l]]==0){
                distinct-- ;
            }
            l++ ;
        }
        subarrays +=(r-l+1);
    }
    cout<<subarrays<<endl;
}
    return 0;
}

