#include<bits/stdc++.h>
using namespace std;

long long rever(long long x){
    long long rev=0;
    while(x!=0){
        long long digit=x%10;
        rev=rev*10 + digit;
        x/=10;
    }
    return rev;
}

bool isprime(long long x){
    if(x<2){
        return false;
    }
    if(x<=3){
        return true;
    }
    if(x%2==0 || x%3==0){
        return false;
    }
    for(long long i=5;i*i<=x;i+=6){
        if(x%i==0 || x%(i+2)==0){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long num;
    cin>>num;
    if(!isprime(num)){
        cout<<"false"<<endl;
        return 0;
    }
    
    long long rev=rever(num);
    long long t1=num,t2=rev;
    long long r1=0,r2=0;
    while(t1>0){
        long long d1=t1%10;
        r1=r1*10 +d1;
        t1/=10;
        long long d2=t2%10;
        r2=r2*10+d2;
        t2/=10;
        if(!isprime(rever(r1)) || !isprime(r2)){
            cout<<"false"<<endl;
            return 0;
        }
    }
    cout<<"true"<<endl;
    return 0;
}












/*You are given an integer num.

A number num is called a Complete Prime Number if every prefix and every suffix of num is prime.

Return true if num is a Complete Prime Number, otherwise return false.

Note:

A prefix of a number is formed by the first k digits of the number.
A suffix of a number is formed by the last k digits of the number.
Single-digit numbers are considered Complete Prime Numbers only if they are prime.
 

Example 1:

Input: num = 23

Output: true

Explanation:

​​​​​​​Prefixes of num = 23 are 2 and 23, both are prime.
Suffixes of num = 23 are 3 and 23, both are prime.
All prefixes and suffixes are prime, so 23 is a Complete Prime Number and the answer is true.
Example 2:

Input: num = 39

Output: false

Explanation:

Prefixes of num = 39 are 3 and 39. 3 is prime, but 39 is not prime.
Suffixes of num = 39 are 9 and 39. Both 9 and 39 are not prime.
At least one prefix or suffix is not prime, so 39 is not a Complete Prime Number and the answer is false.
Example 3:

Input: num = 7

Output: true

Explanation:

7 is prime, so all its prefixes and suffixes are prime and the answer is true.
 

Constraints:

1 <= num <= 109*/