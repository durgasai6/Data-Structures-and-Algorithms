#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long l,r;
    cin>>l>>r;
    long long limit=sqrt(r);
    vector<bool> isprime(limit+1,true);
    isprime[0]=isprime[1]=false;
    for(long long i=2;i*i<=limit;i++){
        if(isprime[i]){
            for(long long j=i*i;j<=limit;j+=i){
                isprime[j]=false;
            }
        }
    }
    vector<long long> primes;
    for(long long i=0;i<=limit;i++){
        if(isprime[i]){
            primes.push_back(i);
        }
    }

    vector<bool> temp(r-l+1,true);
    for(long long p:primes){
        long long first = ((l+ p-1)/p)*p;
        first=max(first,p*p);
        for(long long j=first;j<=r;j+=p){
            temp[j-l]=false;
        }
    }
    if(l == 1){
        temp[0]=false;
    }
    vector<long long> answer;
    for(long long i=0;i<temp.size();i++){
        if(temp[i]==true){
            answer.push_back(l+i);
        }
    }
    
    cout<<answer.size()<<endl;
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
    
    return 0;
}



/*Description

Find all prime numbers between the range from L to R (endpoints inclusive). Print them in non-decreasing order.

Input Format

The only line of input contains L and R, representing the range.

Output Format

The first line of output contains n - the number of prime numbers in between [L, R].
The second line contains n space-separated integers denoting the prime numbers between [L, R] in non-decreasing order.

Constraints

1 ≤ L ≤ R ≤ 1012
R - L + 1 ≤ 106 

Sample Input 1
 Copy

1 20
Sample Output 1
 Copy

8
2 3 5 7 11 13 17 19
Sample Input 2
 Copy

100000000000 100000000020
Sample Output 2
 Copy

2
100000000003 100000000019*/