#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;

long long power(long long a, long long p){
    a=(a%mod);
    long long res=1;
    while(p>0){
        if(p%2!=0){
            res=(a*res)%mod;
        }
        a=(a*a)%mod;
        p=p/2;
    }
    return res;
}

bool specialcheck(int x){
    int original=x;
    int temp=0;
    while(x>0){
        temp=temp*10 +x%10;
        x=x/10;
    }
    long long sum=0;
    int k=1;
    while(temp>0){
        int temp2=temp%10;
        sum+=power(temp2,k);
        temp=temp/10;
        k++;
    }
    return sum==original;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int count=0;
    for(int i=1;i<=n;i++){
        if(specialcheck(i)){
            cout<<i<<" ";
            count++;
        }
    }
    cout<<endl;
    cout<<count;
    return 0;
}









/*Special Numbers Based on Positional Digit Powers
For hiring by: ATMECS
Year Asked: 2023
Round: 1
Difficulty: Easy
Company Type: Dream
Category: Math, Number Theory, Digit Manipulation
________________________________________
Problem Statement
A number is called a Special Number if the sum of its digits raised to the power of their respective positions (starting from 1, from left to right) is equal to the number itself.
You are given a positive integer n. Determine whether n is a Special Number.
Then, extend this logic to find and analyze all Special Numbers between 1 and 10,000.
________________________________________
Definition
For a number n with digits:
d1 d2 d3 ... dk
The number is Special if:
d1^1 + d2^2 + d3^3 + ... + dk^k = n
________________________________________
Examples
Example 1
Input
n = 135
Explanation
1^1 + 3^2 + 5^3 = 1 + 9 + 125 = 135
Output
Special Number
________________________________________
Example 2
Input
n = 89
Explanation
8^1 + 9^2 = 8 + 81 = 89
Output
Special Number
________________________________________
Example 3
Input
n = 80
Explanation
8^1 + 0^2 = 8 ≠ 80
Output
Not a Special Number
________________________________________
Main Task
Write a program to:
1.	Identify all Special Numbers between 1 and 10,000
2.	Display all such Special Numbers
3.	Display the total count of Special Numbers found
________________________________________
Output Format
Special Numbers between 1 and 10000:

Total Special Numbers: <count>
________________________________________
Constraints
•	1 ≤ n ≤ 10,000
•	Position count starts from leftmost digit
•	Powers grow with position index
•	Leading zeros are not allowed
________________________________________
Edge Cases
•	Single-digit numbers should be evaluated correctly
•	Zero within a number contributes 0^position = 0
•	Numbers greater than 10,000 must not be considered
________________________________________
Notes
•	Do not convert digits using mathematical shortcuts that skip positional logic
•	Maintain left-to-right digit ordering
•	Clear separation of validation and aggregation logic is expected
________________________________________

*/