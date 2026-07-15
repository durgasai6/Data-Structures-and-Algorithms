#include<bits/stdc++.h>
using namespace std;


vector<string> printVertically(string s){
    vector<string> words;
    string temp="";
    for(char c:s){
        if(c==' '){
            words.push_back(temp);
            temp="";
            continue;
        }
        temp+=c;
    }
    if(!temp.empty()){
        words.push_back(temp);
    }
    int n=words.size();
    int m=-1;
    for(int i=0;i<n;i++){
        m=max(m,(int)words[i].size());
    }
    vector<string> ans(m,"");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i<words[j].size()){
                ans[i]+=words[j][i];
            }
            else{
                ans[i]+=' ';
            }
        }
    }
    for(int i=0;i<m;i++){
        while((!ans[i].empty()) && (ans[i].back()==' ')){
            ans[i].pop_back();
        }
    }
    
    return ans;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    getline(cin,s);
    vector<string> ans=printVertically(s);
    int n=ans.size();
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}


















/*Given a string s. Return all the words vertically in the same order in which they appear in s.
Words are returned as a list of strings, complete with spaces when is necessary. (Trailing spaces are not allowed).
Each word would be put on only one column and that in one column there will be only one word.

 

Example 1:

Input: s = "HOW ARE YOU"
Output: ["HAY","ORO","WEU"]
Explanation: Each word is printed vertically. 
 "HAY"
 "ORO"
 "WEU"
Example 2:

Input: s = "TO BE OR NOT TO BE"
Output: ["TBONTB","OEROOE","   T"]
Explanation: Trailing spaces is not allowed. 
"TBONTB"
"OEROOE"
"   T"
Example 3:

Input: s = "CONTEST IS COMING"
Output: ["CIC","OSO","N M","T I","E N","S G","T"]
 

Constraints:

1 <= s.length <= 200
s contains only upper case English letters.
It's guaranteed that there is only one space between 2 words.*/