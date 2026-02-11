#include<bits/stdc++.h>
using namespace std;

long long pow(long long a, long long power, long long mod){
    long long result =1;
    a=(a%mod);
    while(power>0){
        if(power%2 !=0){
            result = (result * a)%mod;
        }
        a = (a*a)%mod;
        power = power/2;
    }
    return result;
}

long long operation(long long x, long long y, long long op, long long mod){
    if(op=='+'){
        return (x+y)%mod;
    }
    if(op=='-'){
        return (x-y + mod)%mod;
    }
    if(op=='*'){
        return (x*y)%mod;
    }
    if(op=='/'){
        return (x*pow(y,mod-2,mod))%mod;
    }
    return 0;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long a,b,c,p;
        
        char op1,op2,open,close;
        string modword;
        cin>>open;
        cin>>a>>op1>>b>>op2>>c;
        cin>>close>>modword>>p;
        bool first = (op1=='*' || op1=='/');
        bool second = (op2 == '*'||op2=='/');
        long long answer;
        if(!first && second){
            long long temp = operation(b,c,op2,p);
            answer = operation(a,temp,op1,p);
            
        }
        else{
            long long temp = operation(a,b,op1,p);
            answer = operation(temp,c,op2,p);
        }
        if(answer>=0){
            cout<<answer<<endl;
        }
        else{
            cout<<(answer+p)%p<<endl;
        }
    }
    return 0;
}