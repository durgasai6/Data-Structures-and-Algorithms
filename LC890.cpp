#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<string> words(n);
    for(int i=0;i<n;i++){
        cin>>words[i];
    }
    string pattern;
    cin>>pattern;

    int m=pattern.size();

    vector<string> ans;

    for(int i=0;i<n;i++){
        string s=words[i];

        if(s.size()!=pattern.size()){
            continue;
        }

        unordered_map<char,char> mp1;
        unordered_map<char,char> mp2;
        bool ok=true;
        for(int j=0;j<pattern.size();j++){
            if(mp1.find(pattern[j])==mp1.end() && mp2.find(s[j])==mp2.end()){
                mp1[pattern[j]]=s[j];
                mp2[s[j]]=pattern[j];
            }
            else{
                if(mp1[pattern[j]]!=s[j] || mp2[s[j]]!=pattern[j]){
                    ok=false;
                    break;
                }
            }
        }
        if(ok){
            ans.push_back(s);
        }
        
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}












/*Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.

 

Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.
Example 2:

Input: words = ["a","b","c"], pattern = "a"
Output: ["a","b","c"]
 

Constraints:

1 <= pattern.length <= 20
1 <= words.length <= 50
words[i].length == pattern.length
pattern and words[i] are lowercase English letters.*/