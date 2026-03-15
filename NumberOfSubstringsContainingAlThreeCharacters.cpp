#include<bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int a=0,b=0,c=0;
    
    int left=0,answer=0;
    for(int right=0;right<s.size();right++){
        if(s[right]=='a'){
            a++;
        }
        if(s[right]=='b'){
            b++;
        }
        if(s[right]=='c'){
            c++;
        }
        while(a>0 && b>0 && c>0){
            answer+=s.size()-right;
            if(s[left]=='a'){
                a--;
            }
            if(s[left]=='b'){
                b--;
            }
            if(s[left]=='c'){
                c--;
            }
            left++;
        }
    }
    cout<<answer<<endl;
    return 0;
}




/*Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1
 

Constraints:

3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.*/