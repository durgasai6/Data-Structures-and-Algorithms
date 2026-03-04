#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;
    cin>>s;
    cin>>t;
    int n=s.size();
    int m=t.size();
    stack<char> st1,st2;
    for(int i=0;i<n;i++){
        if(s[i]!='#'){
            st1.push(s[i]);
        }
        else{
            if(!st1.empty()){
                st1.pop();
            }
            else{
                continue;
            }
        }
    }
    for(int i=0;i<m;i++){
        if(t[i]!='#'){
            st2.push(t[i]);
        }
        else{
            if(!st2.empty()){
                st2.pop();
            }
            else{
                continue;
            }
        }
    }
    if(st1.size()!=st2.size()){
        cout<<"false"<<endl;
        return 0;
    }
    while(!st1.empty()){
        if(st1.top()!=st2.top()){
            cout<<"false"<<endl;
            return 0;
        }
        st1.pop();
        st2.pop();
    }
    cout<<"true"<<endl;
    return 0;
}








/*Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

 

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
 

Constraints:

1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.*/