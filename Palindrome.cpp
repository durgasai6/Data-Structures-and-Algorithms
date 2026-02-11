#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        vector<int> freq(26,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        string left="";
        for(int i=0;i<26;i++){
            left.append(freq[i]/2,char('a'+i));
            freq[i]%=2;
        }

        char mid=0;
        for(int i=0;i<26;i++){
            if(freq[i]){
                mid=char('a'+i);
                break;
            }
        }
        string right=left;
        reverse(right.begin(),right.end());
        if(mid){
            cout<<left<<mid<<right<<endl;
        }
        else{
            cout<<left<<right<<endl;
        }
        
    }

    return 0;
}