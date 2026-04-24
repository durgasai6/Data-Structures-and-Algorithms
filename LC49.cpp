#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<string> strs(n);
    for(int i=0;i<n;i++){
        cin>>strs[i];
    }
    unordered_map<string,vector<string>> mp;
    for(int i=0;i<n;i++){
        string temp=strs[i];
        sort(temp.begin(),temp.end());
        mp[temp].push_back(strs[i]);
    }
    vector<vector<string>> ans;
    for(auto &it: mp){
        ans.push_back(it.second);
    }
    for(int i=0;i<ans.size();i++){
        for(string s:ans[i]){
            cout<<s<<" ";
        }
        cout<<endl;
    }
    return 0;
}
















/*Given an array of strings strs, group the anagrams together. You can return the answer in any order.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
Example 2:

Input: strs = [""]

Output: [[""]]

Example 3:

Input: strs = ["a"]

Output: [["a"]]

 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.*/