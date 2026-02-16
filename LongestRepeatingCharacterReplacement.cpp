#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;
    int k;
    cin>>k;
    int n=s.length();
    vector<int> freq(26,0);
    int l=0,maxi=0;
    int answer=INT_MIN;
    for(int r=0;r<n;r++){
        freq[s[r]-'A']++;
        maxi=max(maxi,freq[s[r]-'A']);
        while(r-l+1-maxi>k){
            freq[s[l]-'A']--;
            l++;
        }
        answer=max(answer,r-l+1);
    }
    cout<<answer<<endl;
    return 0;
}


/*You are given a string s and an integer k. 
You can choose any character of the string and change it to any other uppercase English character. 
You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.

 
Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
 

Constraints:

1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length*/