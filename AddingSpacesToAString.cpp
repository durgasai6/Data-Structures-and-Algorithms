#include<bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<int> spaces(n);
    for(int i=0;i<n;i++){
        cin>>spaces[i];
    }
    string ans="";
    int last=0;
    for(int i=0;i<n;i++){
        string left=s.substr(last,spaces[i]-last);
        ans+=left;
        ans+=" ";
        last=spaces[i];
    }
    ans+=s.substr(last);
    cout<<ans<<endl;
    return 0;
}