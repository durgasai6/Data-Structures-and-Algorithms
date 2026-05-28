#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string s=to_string(n);
    if(!next_permutation(s.begin(),s.end())){
        cout<<-1<<endl;
        return 0;
    }
    long long num=stoll(s);
    if(num>INT_MAX){
        cout<<-1<<endl;
        return 0;
    }
    cout<<num<<endl;
    return 0;
}











/*Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.

Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.

 

Example 1:

Input: n = 12
Output: 21
Example 2:

Input: n = 21
Output: -1
 

Constraints:

1 <= n <= 231 - 1*/