#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> freq(26,0);
        for(auto c :s){
            freq[c-'a']++;
        }
        int cntodd=0;
        for(auto x:freq){
            if(x %2!=0){
                cntodd++;
            }
        }
        if(cntodd>1){
            cout<<"-1"<<endl;
            continue;
        }
        int l=0,r=n-1;
        long long swaps=0;
        while (l<r){
            if(s[l] == s[r]){
            l++;
            r--;
        }
        else{
            int a =r;
            while(a>l && s[a] != s[l]){
                a--;
            }
            if(a==l){
                swap(s[l],s[l+1]);
                swaps++;
            }
            else{
                while(a<r){
                    swap(s[a+1],s[a]);
                    swaps++;
                    a++;
                }
                l++;
                r--;
            }
        }
        }
        
        
        cout<<swaps<<endl;
    }
    return -1;
}