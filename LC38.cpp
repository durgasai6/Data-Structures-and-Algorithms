#include<bits/stdc++.h>
using namespace std;

string countAndSay(int n){

    string ans="1";
    
    for(int i=2;i<=n;i++){
        string temp="";
        int j=0;
        while(j<ans.size()){
            int cnt=1;
            while(j+cnt < ans.size() && ans[j]==ans[j+cnt]){
                cnt++;
            }
            temp+=to_string(cnt);
            temp+=ans[j];
            j+=cnt;
        }
        ans=temp;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;

    cout<<countAndSay(n);
    
    return 0;
}













/*The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the run-length encoding of countAndSay(n - 1).
Run-length encoding (RLE) is a string compression method that works by replacing each maximal group of consecutive identical characters with the concatenation of the length of the group followed by the character itself. For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15", and replace "1" with "11". Thus the compressed string becomes "23321511".

Given a positive integer n, return the nth element of the count-and-say sequence.

 

Example 1:

Input: n = 4

Output: "1211"

Explanation:

countAndSay(1) = "1"
countAndSay(2) = RLE of "1" = "11"
countAndSay(3) = RLE of "11" = "21"
countAndSay(4) = RLE of "21" = "1211"
Example 2:

Input: n = 1

Output: "1"

Explanation:

This is the base case.

 

Constraints:

1 <= n <= 30*/