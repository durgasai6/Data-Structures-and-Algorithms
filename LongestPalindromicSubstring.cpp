#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n=s.length();

    int current=0, len=1;
    for(int i=0;i<n;i++){
        int l=i,r=i;
        while(l>=0 && r<n && s[l]==s[r]){
            if(r-l+1>len){
                current=l;
                len=r-l+1;
            }
            r++;
            l--;
        }

        l=i;
        r=l+1;
        while(l>=0 && r<n && s[l]==s[r]){
            if(r-l+1>len){
                current=l;
                len=r-l+1;
            }
            r++;
            l--;

        }
    }
    cout<<s.substr(current, len);
    return 0;
}








/*Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.*/