#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    vector<int> pos(26,-1);
    vector<int> freq(26,0);
    vector<pair<char,int>> f;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
            freq[s[i]-'a']++;
            if(pos[s[i]-'a']==-1){
                pos[s[i]-'a']=i;
            }
        }
    }

    for(int i=0;i<freq.size();i++){
        if(freq[i]!=0){
            char c=i+'a';
            f.push_back({c,freq[i]});
        }
    }

    sort(f.begin(),f.end(),[&](pair<char,int> &a, pair<char,int> &b){
        if(a.second == b.second){
            return pos[a.first-'a']<pos[b.first-'a'];
        }
        return a.second>b.second;
    });



    string ans="";
    int idx=0;
    for(int i=0;i<n;i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
            ans+=f[idx].first;
            f[idx].second--;

            if(f[idx].second==0){
                idx++;
            }
        }
        else{
            ans+=s[i];
        }
    }

    cout<<ans<<endl;
    
    return 0;
}












/*You are given a string s consisting of lowercase English characters.

Rearrange only the vowels in the string so that they appear in non-increasing order of their frequency.

If multiple vowels have the same frequency, order them by the position of their first occurrence in s.

Return the modified string.

Vowels are 'a', 'e', 'i', 'o', and 'u'.

The frequency of a letter is the number of times it occurs in the string.

 

Example 1:

Input: s = "leetcode"

Output: "leetcedo"

Explanation:​​​​​​​

Vowels in the string are ['e', 'e', 'o', 'e'] with frequencies: e = 3, o = 1.
Sorting in non-increasing order of frequency and placing them back into the vowel positions results in "leetcedo".
Example 2:

Input: s = "aeiaaioooa"

Output: "aaaaoooiie"

Explanation:​​​​​​​

Vowels in the string are ['a', 'e', 'i', 'a', 'a', 'i', 'o', 'o', 'o', 'a'] with frequencies: a = 4, o = 3, i = 2, e = 1.
Sorting them in non-increasing order of frequency and placing them back into the vowel positions results in "aaaaoooiie".
Example 3:

Input: s = "baeiou"

Output: "baeiou"

Explanation:

Each vowel appears exactly once, so all have the same frequency.
Thus, they retain their relative order based on first occurrence, and the string remains unchanged.
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters*/