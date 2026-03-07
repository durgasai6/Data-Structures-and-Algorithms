#include<bits/stdc++.h>
using namespace std;

bool primes(int x){
    if(x==0 || x==1){
        return false;
    }
    if(x==2 || x==3){
        return true;
    }
    if(x%2==0 || x%3==0){
        return false;
    }
    for(int i=5;i*i<=x;i+=6){
        if((x%i)==0 || ((x)%(i+2))==0){
            return false;
        }
    }
    return true;
}

bool endingnine(int x){
    int temp=x;
    if(temp%10==9){
        return true;
    }
    return false;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    cin>>x;
    vector<int> prime;
    for(int i=0;i<=x;i++){
        if(primes(i)){
            prime.push_back(i);
        }
        else{
            continue;
        }
    }
    int count=0;


    int k=0;
    while(k<x){
        int y=k+100;
        cout<<"prime numbers from "<<k<<" to "<<min(x,y)<<" :";
        for(int i=0;i<prime.size();i++){
            if(prime[i]>=k && prime[i]<y && endingnine(prime[i])){
                cout<<prime[i]<<" ";
                count++;
            }
            else if(prime[i]>=y){
                break;
            }
        }
        cout<<endl;
        k+=100;
    }
    cout<<count<<endl;
    return 0;
}








/*Problem Statement – Prime Numbers Ending with 9
For hiring by: Eurofins
Year Asked: 2023
Round: 1
Difficulty: Easy
Company Type: Super Dream
Write a program to generate all prime numbers from 1 to 10,000 that end with the digit 9.
A prime number is a number greater than 1 that has no divisors other than 1 and itself.
Your program must perform the following tasks:

Step 1: Generate Prime Numbers
Check all numbers from 1 to 10,000.
Identify the numbers that:
Are prime, and
End with the digit 9.

Step 2: Display Results in Groups of 100
After generating the required prime numbers, display them in ranges of 100 numbers as shown below.
For each range:
Display the range of numbers.
Display the count of prime numbers ending with 9 in that range.
Display the prime numbers themselves.
 
Example output format:
Number of prime numbers from 0 to 99 = 5
19  29  59  79  89
 
Number of prime numbers from 100 to 199 = 5
109  139  149  179  199
 
Number of prime numbers from 200 to 299 = 3
229  239  269
Continue this pattern for all ranges:
0–99
100–199
200–299
…
9800–9899
9900–9999

Step 3: Display Final Count
After processing all ranges, display the total number of prime numbers ending with 9 between 1 and 10,000.
Example:
Total prime numbers from 1 to 10000 ending with 9 = 303
*/