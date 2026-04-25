#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<string> dictionary(n);
    for(int i=0;i<n;i++){
        cin>>dictionary[i];
    }
    int i=0,j=0;
    string ans="";
    for(string word: dictionary){
        i=0,j=0;
        while(i<s.size() && j<word.size()){
            if(s[i]==word[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        if(j==word.size()){
            if(word.size()>ans.size() || (word.size()==ans.size() && word<ans)){
                ans=word;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}









/*Given a string s and a string array dictionary, return the longest string in the dictionary that can be formed by deleting some of the given string characters. If there is more than one possible result, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

 

Example 1:

Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
Output: "apple"
Example 2:

Input: s = "abpcplea", dictionary = ["a","b","c"]
Output: "a"
 

Constraints:

1 <= s.length <= 1000
1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 1000
s and dictionary[i] consist of lowercase English letters.*/