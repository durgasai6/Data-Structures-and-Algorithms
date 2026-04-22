#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    getline(cin, s);
    vector<string> str;
    string temp="";
    for(char c:s){
        if(c==' ' ){
            if(!temp.empty()){
                str.push_back(temp);
                temp="";
            }
        }else{
            temp+=c;
        }
    }

    if(!temp.empty()){
        str.push_back(temp);
    }
    int cnt=0;
    string first=str[0];
    for(char c:first){
        if(c=='a' || c=='e' ||c=='i'|| c=='o' || c=='u'){
            cnt++;
        }
    }
    int x=0;
    for(int i=1;i<str.size();i++){
        string curr=str[i];
        for(char c:curr){
            if(c=='a' || c=='e' ||c=='i'|| c=='o' || c=='u'){
                x++;
            }
        }
        if(x==cnt){
            reverse(str[i].begin(),str[i].end());
        }
        x=0;
    }
    for(string k: str){
        cout<<k<<" ";
    }

    return 0;
}














/*You are given a string s consisting of lowercase English words, each separated by a single space.

Determine how many vowels appear in the first word. Then, reverse each following word that has the same vowel count. Leave all remaining words unchanged.

Return the resulting string.

Vowels are 'a', 'e', 'i', 'o', and 'u'.

 

Example 1:

Input: s = "cat and mice"

Output: "cat dna mice"

Explanation:​​​​​​​

The first word "cat" has 1 vowel.
"and" has 1 vowel, so it is reversed to form "dna".
"mice" has 2 vowels, so it remains unchanged.
Thus, the resulting string is "cat dna mice".
Example 2:

Input: s = "book is nice"

Output: "book is ecin"

Explanation:

The first word "book" has 2 vowels.
"is" has 1 vowel, so it remains unchanged.
"nice" has 2 vowels, so it is reversed to form "ecin".
Thus, the resulting string is "book is ecin".
Example 3:

Input: s = "banana healthy"

Output: "banana healthy"

Explanation:

The first word "banana" has 3 vowels.
"healthy" has 2 vowels, so it remains unchanged.
Thus, the resulting string is "banana healthy".
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters and spaces.
Words in s are separated by a single space.
s does not contain leading or trailing spaces.*/