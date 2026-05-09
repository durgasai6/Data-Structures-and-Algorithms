#include<bits/stdc++.h>
using namespace std;


int reversenum(int n){
    int rev=0;
    while(n>0){
        int digit=n%10;
        rev=rev*10 + digit;
        n=n/10;
    }
    return rev;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int k=1000;
    vector<bool> prime(k+1,true);
    prime[0]=false;
    prime[1]=false;
    for(int i=2;i*i<=k;i++){
        if(prime[i]){
            for(int j=i*i;j<=k;j+=i){
                prime[j]=false;
            }
        }
    }
    int reve=reversenum(n);
    int sum=0;
    for(int i=min(n,reve);i<=max(n,reve);i++){
        if(prime[i]){
            sum+=i;
        }
    }
    cout<<sum<<endl;
    return 0;
}










/*You are given an integer n.

Let r be the integer formed by reversing the digits of n.

Return the sum of all prime numbers between min(n, r) and max(n, r), inclusive.

 

Example 1:

Input: n = 13

Output: 132

Explanation:

The reverse of 13 is 31. Thus, the range is [13, 31].
The prime numbers in this range are 13, 17, 19, 23, 29, and 31.
The sum of these prime numbers is 13 + 17 + 19 + 23 + 29 + 31 = 132.
Example 2:

Input: n = 10

Output: 17

Explanation:

The reverse of 10 is 1. Thus, the range is [1, 10].
The prime numbers in this range are 2, 3, 5, and 7.
The sum of these prime numbers is 2 + 3 + 5 + 7 = 17.
Example 3:

Input: n = 8

Output: 0

Explanation:

The reverse of 8 is 8. Thus, the range is [8, 8].
There are no prime numbers in this range, so the sum is 0.
 

Constraints:

1 <= n <= 1000
*/