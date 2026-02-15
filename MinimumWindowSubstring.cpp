#include<bits/stdc++.h>
using namespace std;


int main(){
    string s,t;
    cin>>s;
    cin>>t;
    int st=t.size();
    vector<int> freq(150,0);
    for(int i=0;i<t.size();i++){
        freq[t[i]]++;
    }
    int l=0, len = INT_MAX, count=0,start=0;
    int required=t.size();
    for(int r=0;r<s.size();r++){
        if(freq[s[r]]>0){
            count++;
        }
        freq[s[r]]--;

        while(count==required){
            if(r-l+1 < len){
                len=r-l+1;
                start=l;
            }
            freq[s[l]]++;
            if(freq[s[l]]>0){
                count--;
            }
            l++;
        }
    }
    if(len==INT_MAX){
        cout<<""<<endl;
    }
    else{
        cout<<s.substr(start,len)<<endl;
    }
    return 0;
}


/*Given two strings s and t of lengths m and n respectively, 
return the minimum window substring of s such that every character in t (including duplicates) is included in the window. 
If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.

 
Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.*/