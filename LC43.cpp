#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string num1,num2;
    cin>>num1>>num2;
    int n=num1.size();
    int m=num2.size();
    vector<int> res(n+m,0);
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            int temp=(num1[i]-'0')*(num2[j]-'0');
            int curr=temp+res[i+j+1];

            res[i+j+1]=curr%10;
            res[i+j]+=curr/10;
        }
    }
    string ans="";
    for(int x:res){
        if(!ans.empty() || x!=0){
            ans+=to_string(x);
        }
    }
    cout<<ans<<endl;
    return 0;
}












/*Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

 

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
 

Constraints:

1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.*/