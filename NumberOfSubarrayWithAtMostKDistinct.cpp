#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        if(k==0){
            cout<<0<<endl;
            continue;
        }
        unordered_map<int,int> freq;
        int l=0,distinct=0;
        long long answer=0;
        for(int r=0;r<n;r++){
            if(freq[a[r]]==0){
                distinct++;
            }
            freq[a[r]]++;

            while(distinct >k){
                freq[a[l]]--;
                if(freq[a[l]]==0){
                    distinct--;
                }
                l++;
            }
            answer+=(r-l+1);
        }
        cout<<answer<<endl;
    }
    return 0;
}