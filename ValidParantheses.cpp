#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n=s.size();
    stack<char> st;
    for(int i=0;i<n;i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            st.push(s[i]);
        }
        else{
            if(st.empty()){
                cout<<"false"<<endl;
                return 0;
            }
            else if(s[i]==')'){
                if(st.top()=='('){
                    st.pop();
                }
                else{
                    cout<<"false"<<endl;
                    return 0;
                }
            }   
            else if(s[i]=='}'){
                if(st.top()=='{'){
                    st.pop();
                }
                else{
                    cout<<"false"<<endl;
                    return 0;
                }
            }
            else if(s[i]==']'){
                if(st.top()=='['){
                    st.pop();
                }
                else{
                    cout<<"false"<<endl;
                    return 0;
                }
            }
        }   
    }
    if(st.empty()){
        cout<<"true"<<endl;
    }
    if(!st.empty()){
        cout<<"false"<<endl;
    }
    return 0;
}



/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false

 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.*/