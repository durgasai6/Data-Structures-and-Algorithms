#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s1,s2;
    cin>>s1>>s2;
    int n=s1.size();
    int m=s2.size();
    if(n>m){
        cout<<"false"<<endl;
        return 0;
    }
    vector<int> freq1(26,0),freq2(26,0);
    for(int i=0;i<n;i++){
        freq1[s1[i]-'a']++;
        freq2[s2[i]-'a']++;
    }
    if(freq1==freq2){
        cout<<"true"<<endl;
        return 0;
    }
    for(int i=n;i<m;i++){
        freq2[s2[i]-'a']++;
        freq2[s2[i-n]-'a']--;
        if(freq1==freq2){
            cout<<"true"<<endl;
            return 0;
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