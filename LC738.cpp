#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string s=to_string(n);
    int m=s.length();
    int mark=m;
    for(int i=m-1;i>0;i--){
        if(s[i]<s[i-1]){
            s[i-1]--;
            mark=i;
        }
    }
    for(int i=mark;i<m;i++){
        s[i]='9';
    }
    cout<<stoi(s)<<endl;
    return 0;
}











/*An integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.

Given an integer n, return the largest number that is less than or equal to n with monotone increasing digits.

 

Example 1:

Input: n = 10
Output: 9
Example 2:

Input: n = 1234
Output: 1234
Example 3:

Input: n = 332
Output: 299
 

Constraints:

0 <= n <= 109*/