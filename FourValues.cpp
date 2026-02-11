#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long x;
    cin>>n>>x;
    vector<long long> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    unordered_set<long long> pairsum;
    for(int l=1;l<n;l++){
        for(int h=l+1;h<n;h++){
            long long remaining = x-a[l]-a[h];
            if(pairsum.count(remaining)){
                cout<<"YES"<<endl;
                return 0;
            }
        }
        for(int i=0;i<l;i++){
            pairsum.insert(a[i]+a[l]);
        }
    }
    cout<<"NO"<<endl;
    return 0;
}