#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long c;
    cin>>c;
    long long a,b;
    a=0;
    b=sqrt(c);
    while(a<=b){
        long long sum=a*a + b*b;
        if(sum==c){
            cout<<"true"<<endl;
            return 0;
        }
        else if(sum<c){
            a++;
        }
        else{
            b--;
        }
    }
    cout<<"false"<<endl;
    return 0;
}









/*Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

 

Example 1:

Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:

Input: c = 3
Output: false
 

Constraints:

0 <= c <= 231 - 1*/