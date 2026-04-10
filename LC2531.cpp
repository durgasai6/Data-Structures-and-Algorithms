#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string word1,word2;
    cin>>word1>>word2;
    vector<int> freq1(26,0), freq2(26,0);
    int distinct1=0, distinct2=0;
    for(char c:word1){
        freq1[c-'a']++;
    }
    for(char c:word2){
        freq2[c-'a']++;
    }
    for(int i=0;i<26;i++){
        if(freq1[i]){
            distinct1++;
        }
        if(freq2[i]){
            distinct2++;
        }
    }

    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            if(freq1[i]==0 || freq2[j] == 0){
                continue;
            }
            int t1=distinct1;
            int t2=distinct2;
            if(freq1[i]==1){
                t1--;
            }
            if(freq1[j]==0){
                t1++;
            }
            if(freq2[j]==1){
                t2--;
            }
            if(freq2[i]==0){
                t2++;
            }
            if(t1==t2){
                cout<<"true"<<endl;
                return 0;
            }
        }
    }
    cout<<"false"<<endl;
    return 0;
}




















/*You are given two 0-indexed strings word1 and word2.

A move consists of choosing two indices i and j such that 0 <= i < word1.length and 0 <= j < word2.length and swapping word1[i] with word2[j].

Return true if it is possible to get the number of distinct characters in word1 and word2 to be equal with exactly one move. Return false otherwise.

 

Example 1:

Input: word1 = "ac", word2 = "b"
Output: false
Explanation: Any pair of swaps would yield two distinct characters in the first string, and one in the second string.
Example 2:

Input: word1 = "abcc", word2 = "aab"
Output: true
Explanation: We swap index 2 of the first string with index 0 of the second string. The resulting strings are word1 = "abac" and word2 = "cab", which both have 3 distinct characters.
Example 3:

Input: word1 = "abcde", word2 = "fghij"
Output: true
Explanation: Both resulting strings will have 5 distinct characters, regardless of which indices we swap.
 

Constraints:

1 <= word1.length, word2.length <= 105
word1 and word2 consist of only lowercase English letters.*/