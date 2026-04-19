#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;
    cin>>a>>b;
    while(b!=0){
        int carry=(a&b)<<1;
        a=a^b;
        b=carry;
    }
    cout<<a<<endl;
    return 0;
}














/*Given two integers a and b, return the sum of the two integers without using the operators + and -.

 

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = 2, b = 3
Output: 5
 

Constraints:

-1000 <= a, b <= 1000*/