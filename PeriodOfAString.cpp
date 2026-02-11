#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int z=1;z<=t;z++){
        int n;
        cin>>n;
        string s;
        cin>>s;
        cout<<"Test Case #"<<z<<endl;

        vector<int> lps(n,0);
        int length=0,i=1;

        while(i<n){
            if(s[i] == s[length]){
                length++;
                lps[i] = length;
                i++;
            }
            else{
                if(length!=0){
                    length = lps[length-1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        for(int i=2;i<=n;i++){
            int end = lps[i-1];
            int len = i-end;
            if(i%len == 0){
                int k=i/len;
                if(k>1){
                    cout<<i<<" "<<k<<endl;
                }
            }
        }

        cout<<endl;
    }

    
    return 0;
}