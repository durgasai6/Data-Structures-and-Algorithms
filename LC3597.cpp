#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    string ans="";
    vector<string> result;
    unordered_map<string,int> mp;
    for(int i=0;i<s.size();i++){
        ans+=s[i];
        if(mp.find(ans)==mp.end()){
            result.push_back(ans);
            mp[ans]=1;
            ans="";
        }else{
            continue;
        }
    }
    for(string s: result){
        cout<<s<<" ";
    }

    return 0;
}











/*Given a string s, partition it into unique segments according to the following procedure:

Start building a segment beginning at index 0.
Continue extending the current segment character by character until the current segment has not been seen before.
Once the segment is unique, add it to your list of segments, mark it as seen, and begin a new segment from the next index.
Repeat until you reach the end of s.
Return an array of strings segments, where segments[i] is the ith segment created.

 

Example 1:

Input: s = "abbccccd"

Output: ["a","b","bc","c","cc","d"]

Example 2:

Input: s = "aaaa"

Output: ["a","aa"]
 

Constraints:

1 <= s.length <= 105
s contains only lowercase English letters.*/