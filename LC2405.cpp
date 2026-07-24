#include<bits/stdc++.h>
using namespace std;

int partitionString(string s){
    unordered_map<char,int> mp;
    int ans=1;
    for(char c:s){
        if(mp.find(c)!=mp.end()){
            
            ans++;
            mp.clear();
        }
        mp[c]++;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;

    cout<<partitionString(s);


    return 0;
}










/*Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. That is, no letter appears in a single substring more than once.

Return the minimum number of substrings in such a partition.

Note that each character should belong to exactly one substring in a partition.

 

Example 1:

Input: s = "abacaba"
Output: 4
Explanation:
Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
It can be shown that 4 is the minimum number of substrings needed.
Example 2:

Input: s = "ssssss"
Output: 6
Explanation:
The only valid partition is ("s","s","s","s","s","s").
 

Constraints:

1 <= s.length <= 105
s consists of only English lowercase letters.*/