#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<long long> pref(n+1,0);
    for(int i=1;i<=n;i++){
        pref[i]=nums[i-1]+pref[i-1];
    }
    long long answer=0;
    unordered_map<long long, int> freq;
    freq[0]=1;
    for(int i=0;i<=n;i++){
        if(freq.count(pref[i]-k)){
            answer+=freq[pref[i]-k];
        }
        freq[pref[i]]++;
    }
    cout<<answer<<endl;
    return 0;
}