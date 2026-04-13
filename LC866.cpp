#include<bits/stdc++.h>
using namespace std;

bool isprime(int x){
    if(x<2){
        return false;
    }
    if(x<=3){
        return true;
    }
    if(x%2==0 || x%3==0){
        return false;
    }
    for(int i=5;i*i<x;i+=6){
        if(x%i==0 || (x%(i+2))==0){
            return false;
        }
    }
    return true;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;

    if(n>=8 && n<=11){
        cout<<11<<endl;
    }
    for(int i=1;i<100000;i++){
        string s=to_string(i);
        string rev=s;
        reverse(rev.begin(),rev.end());
        string palindrome=s+ rev.substr(1);
        int num=stoi(palindrome);
        if(num>=n && isprime(num)){
            cout<<num<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;



    return 0;
}













/*Given an integer n, return the smallest prime palindrome greater than or equal to n.

An integer is prime if it has exactly two divisors: 1 and itself. Note that 1 is not a prime number.

For example, 2, 3, 5, 7, 11, and 13 are all primes.
An integer is a palindrome if it reads the same from left to right as it does from right to left.

For example, 101 and 12321 are palindromes.
The test cases are generated so that the answer always exists and is in the range [2, 2 * 108].

 

Example 1:

Input: n = 6
Output: 7
Example 2:

Input: n = 8
Output: 11
Example 3:

Input: n = 13
Output: 101
 

Constraints:

1 <= n <= 108*/