#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s1,s2;
    cin>>s1;
    cin>>s2;
    if(s2.size()<s1.size()){
        cout<<"false"<<endl;
        return 0;
    }
    vector<int> freq(26,0);
    for(int i=0;i<s1.size();i++){
        freq[s1[i]-'a']++;
    }
    int left=0;
    for(int right=0;right<s2.size();right++){
        freq[s2[right]-'a']--;
        if(right-left+1>s1.size()){
            freq[s2[left]-'a']++;
            left++;
        }
        if(right-left +1 == s1.size()){
            int i=0;
            while(i<26 && freq[i]==0){
                i++;
            }
            if(i==26){
                cout<<"true"<<endl;
                return 0;
            }
        }
    }
    cout<<"false"<<endl;
    return 0;
}










/*Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.*/