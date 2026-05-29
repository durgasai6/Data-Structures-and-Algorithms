#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<string> source(n);
    for(int i=0;i<n;i++){
        cin>>source[i];
    }
    vector<string> ans;
    string temp="";
    bool comment=false;
    for(string s: source){
        for(int i=0;i<s.size();i++){
            if(comment && ((i+1<s.size()) && s[i]=='*' &&s[i+1]=='/')){
                comment=false;
                i++;
            }
            else if(!comment && i+1<s.size() && (s[i]=='/' && s[i+1]=='*')){
                comment=true;
                i++;
            }
            else if(!comment && i+1<s.size() && (s[i]=='/' && s[i+1]=='/')){
                break;
            }
            
            
            else if(!comment){
                temp+=s[i];
            }
        }
        if(!comment && !temp.empty()){
            ans.push_back(temp);
            temp="";
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" "<<endl;
    }
    return 0;
}




















