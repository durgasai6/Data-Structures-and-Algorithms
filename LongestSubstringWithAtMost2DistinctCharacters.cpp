#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;
    int l=0;
    int answer=0,distinct=0;
    vector<int> freq(26,0);
    for(int r=0;r<s.size();r++){
        freq[s[r]-'a']++;
        if(freq[s[r]-'a']==1){
            distinct++;
        }
        
        while(distinct>2){
            freq[s[l]-'a']--;
            if(freq[s[l]-'a']==0){
                distinct--;
            }
            l++;
        }
        answer=max(answer,r-l+1);
    }
    cout<<answer<<endl;
    return 0;
}

/*Given a string s, return the length of the longest substring that contains at most two distinct characters.*/