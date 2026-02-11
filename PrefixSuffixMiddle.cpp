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
        vector<int> lps(n,0);
        for(int i=1;i<n;i++){
            int j = lps[i-1];
            while(j>0 && s[i] != s[j]){
                j = lps[j-1];
            }
            if(s[i] == s[j]){
                j++;
            }
            lps[i] = j;
        }
        int len = lps[n-1];

        while(len>0){
            bool found = false;

            for(int i=0;i<n-1;i++){
                if(lps[i] == len){
                    found = true;
                    break;
                }
            }
            if(found){
                cout<<s.substr(0,len)<<endl;
                break;
            }
            len = lps[len-1];
        }
        if(len==0){
            cout<<-1<<endl;
        }
    }
    return 0;
}