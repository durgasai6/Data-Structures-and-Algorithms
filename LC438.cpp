#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s,t;
    cin>>s>>t;
    vector<int> ans;
    int n=s.size();
    int m=t.size();
    if(m>n){
        return 0;
    }
    vector<int> pfreq(26,0),sfreq(26,0);
    for(char c:t){
        pfreq[c-'a']++;
    }
    for(int i=0;i<m;i++){
        sfreq[s[i]-'a']++;
    }
    if(sfreq==pfreq){
        ans.push_back(0);
    }
    for(int right=m;right<n;right++){
        sfreq[s[right]-'a']++;
        sfreq[s[right-m]-'a']--;
        if(sfreq==pfreq){
            ans.push_back(right-m+1);
        }
    }
    for(int x:ans){
        cout<<x<<" ";
    }
    return 0;
}


















/*Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 

Constraints:

1 <= s.length, p.length <= 3 * 104
s and p consist of lowercase English letters.*/