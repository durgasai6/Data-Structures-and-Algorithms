#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;
    cin>>s>>t;
    int i=0;
    if(s.size()!=t.size()){
        cout<<"false"<<endl;
        return 0;
    }
    int l=0,r=0;
    int n=s.size();
    while(l<n || r<n){
        while(l<n && s[l]=='X'){
            l++;
        }
        while(r<n && t[r]=='X'){
            r++;
        }
        if(l==n && r==n){
            cout<<"true"<<endl;
            return 0;
        }
        if(s[l]!=t[r]){
            cout<<"false"<<endl;
            return 0;
        }
        
        if(s[l]=='R'){
            if(l>r){
                cout<<"false"<<endl;
                return 0;
            }
        }
        if(s[l]=='L'){
            if(l<r){
                cout<<"false"<<endl;
                return 0;
            }
        }
        l++;
        r++;
    }
    cout<<"true"<<endl;
    return 0;
}












/*In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move consists of either replacing one occurrence of "XL" with "LX", or replacing one occurrence of "RX" with "XR". Given the starting string start and the ending string result, return True if and only if there exists a sequence of moves to transform start to result.

 

Example 1:

Input: start = "RXXLRXRXL", result = "XRLXXRRLX"
Output: true
Explanation: We can transform start to result following these steps:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX
Example 2:

Input: start = "X", result = "L"
Output: false
 

Constraints:

1 <= start.length <= 104
start.length == result.length
Both start and result will only consist of characters in 'L', 'R', and 'X'.*/