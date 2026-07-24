#include<bits/stdc++.h>
using namespace std;

int findTheLongestSubstring(string s){
    vector<int> first(32,INT_MAX);

    int mask=0,ans=0;

    first[0]=-1;

    for(int i=0;i<s.size();i++){
        if(s[i]=='a'){
            mask^=(1<<0);
        }
        else if(s[i]=='e'){
            mask^=(1<<1);
        }
        else if(s[i]=='i'){
            mask^=(1<<2);
        }
        else if(s[i]=='o'){
            mask^=(1<<3);
        }
        else if(s[i]=='u'){
            mask^=(1<<4);
        }

        if(first[mask]==INT_MAX){
            first[mask]=i;
        }
        else{
            ans=max(ans,i-first[mask]);
        }
    }
    return ans;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;

    cout<<findTheLongestSubstring(s);

    return 0;
}












/*Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.

 

Example 1:

Input: s = "eleetminicoworoep"
Output: 13
Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.
Example 2:

Input: s = "leetcodeisgreat"
Output: 5
Explanation: The longest substring is "leetc" which contains two e's.
Example 3:

Input: s = "bcbcbc"
Output: 6
Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.
 

Constraints:

1 <= s.length <= 5 x 10^5
s contains only lowercase English letters.*/