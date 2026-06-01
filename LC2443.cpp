#include<bits/stdc++.h>
using namespace std;

int reversed(int num){
    int res=0;
    while(num>0){
        int digit=num%10;
        num=num/10;
        res=res*10;
        res+=digit;
    }
    return res;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin>>num;
    for(int i=0;i<=num;i++){
        int rev=reversed(i);
        if(i+rev==num){
            cout<<"true"<<endl;
            return 0;
        }
    }
    cout<<"false"<<endl;
    return 0;
}














/*Given a non-negative integer num, return true if num can be expressed as the sum of any non-negative integer and its reverse, or false otherwise.

 

Example 1:

Input: num = 443
Output: true
Explanation: 172 + 271 = 443 so we return true.
Example 2:

Input: num = 63
Output: false
Explanation: 63 cannot be expressed as the sum of a non-negative integer and its reverse so we return false.
Example 3:

Input: num = 181
Output: true
Explanation: 140 + 041 = 181 so we return true. Note that when a number is reversed, there may be leading zeros.
 

Constraints:

0 <= num <= 105*/