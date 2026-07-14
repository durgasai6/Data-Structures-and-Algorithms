#include<bits/stdc++.h>
using namespace std;

string reverseParantheses(string s){
    stack<int> st;
    int n=s.size();
    string ans="";
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            st.push(i);
        }
        else if(s[i]==')'){
            reverse(s.begin()+st.top(),s.begin()+i+1);
            st.pop();
        }
    }

    for(char c:s){
        if(c>='a' && c<='z'){
            ans+=c;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    cout<<reverseParantheses(s);
    return 0;
}









/*You are given a string s that consists of lower case English letters and brackets.

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any brackets.

 

Example 1:

Input: s = "(abcd)"
Output: "dcba"
Example 2:

Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.
Example 3:

Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
 

Constraints:

1 <= s.length <= 2000
s only contains lower case English characters and parentheses.
It is guaranteed that all parentheses are balanced.*/