#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,s,m;
    cin>>n>>s>>m;
    
    if(n==1){
        ;cout<<s<<endl;
        return 0;
    }
    long long k=n/2;
    long long ans=1LL*s+k*m-(k-1);

    

    cout<<ans;

    return 0;
}










/*You are given three integers n, s, and m.

A sequence seq of integers of length n is considered valid if:

seq[0] = s.
The sequence is alternating, meaning that either:
seq[0] > seq[1] < seq[2] > ..., or
seq[0] < seq[1] > seq[2] < ....
For every adjacent pair, |seq[i] - seq[i - 1]| <= m.
A sequence of length 1 is considered alternating.

Return the maximum possible element that can appear in any valid sequence.

 

Example 1:

Input: n = 4, s = 3, m = 5

Output: 12

Explanation:

One valid sequence is [3, 8, 7, 12].
The maximum element in the sequence is 12.
Example 2:

Input: n = 2, s = 4, m = 3

Output: 7

Explanation:

One valid sequence is [4, 7].
The maximum element in the sequence is 7.
 

Constraints:

1 <= n, s <= 109
1 <= m <= 105*/