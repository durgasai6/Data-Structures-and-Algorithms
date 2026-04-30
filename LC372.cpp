#include<bits/stdc++.h>
using namespace std;

const int mod=1337;

long long power(long long a, long long b){
    long long res=1;
    while(b>0){
        if(b%2!=0){
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        b/=2;
    }
    return (res)%mod;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long a,n;
    cin>>a>>n;
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int res=1;
    for(int x:b){
        res=power(res,10)*power(a,x)%mod;
    }
    cout<<res<<endl;
    return 0;
}













/*Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

 

Example 1:

Input: a = 2, b = [3]
Output: 8
Example 2:

Input: a = 2, b = [1,0]
Output: 1024
Example 3:

Input: a = 1, b = [4,3,3,8,5,2]
Output: 1
 

Constraints:

1 <= a <= 231 - 1
1 <= b.length <= 2000
0 <= b[i] <= 9
b does not contain leading zeros.*/