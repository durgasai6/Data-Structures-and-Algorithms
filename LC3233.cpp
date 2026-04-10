#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long l, r;
    cin>>l>>r;
    long long last=sqrt(r);
    vector<bool> primes(last,true);
    primes[0]=false;
    primes[1]=false;
    for(int i=2;i<=last;i++){
        if(primes[i]){
            for(int j=i*i;j<=last;j+=i){
                primes[j]=false;
            }
        }
    }
    int ans=0;
    for(int i=2;i<=last;i++){
        if(primes[i]){
            long long actual=1LL*i*i;
            if(actual>=l && actual<=r){
                ans++;
            }
        }
    }
    cout<<(r-l+1)-(ans)<<endl;
    
    return 0;
}













/*You are given 2 positive integers l and r. For any number x, all positive divisors of x except x are called the proper divisors of x.

A number is called special if it has exactly 2 proper divisors. For example:

The number 4 is special because it has proper divisors 1 and 2.
The number 6 is not special because it has proper divisors 1, 2, and 3.
Return the count of numbers in the range [l, r] that are not special.

 

Example 1:

Input: l = 5, r = 7

Output: 3

Explanation:

There are no special numbers in the range [5, 7].

Example 2:

Input: l = 4, r = 16

Output: 11

Explanation:

The special numbers in the range [4, 16] are 4 and 9.

 

Constraints:

1 <= l <= r <= 109*/