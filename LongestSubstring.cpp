#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        string c;
        cin>>c;

        int normal=0;
        int l=0;
        int answer=0;
        for(int h=0;h<n;h++){
            if(c[s[h]-'a']=='0'){
                normal++;
            }
        
        while(normal>k){
            if(c[s[l]-'a']=='0'){
                normal--;
            }
            l++;
        }
        answer=(max(answer,h-l+1));
    }
    cout<<answer<<endl;
    }
    return 0;
}