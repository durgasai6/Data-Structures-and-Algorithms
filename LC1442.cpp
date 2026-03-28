#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_map<int, vector<int>> pref;
    int prefix=0;
    int ans=0;
    pref[0].push_back(-1);
    for(int i=0;i<n;i++){
        prefix ^=arr[i];
        if(pref.find(prefix)!=pref.end()){
            for(int p:pref[prefix]){
                ans+=(i-p-1);
            }
        }
        pref[prefix].push_back(i);
    }

    cout<<ans<<endl;

    return 0;
}