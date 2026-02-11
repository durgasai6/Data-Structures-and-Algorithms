#include<bits/stdc++.h>
using namespace std;

bool isprime(long long a){
    if(a<=1){
        return false;
    }
    if(a<=3){
        return true;
    }
    if(a%2 == 0|| a%3 == 0){
        return false;
    }

    for(int i=5;i*i<=a;i+=6){
        if((a%i == 0)|| a%(i+2)==0){
            return false;
        }
    }
    return true;
}

int main(){
    long long a,b;
    cin>>a>>b;
    int cnt=0;
    if(a<=11 && 11<=b){
        cnt++;
    }

    for(int i=1;i<=99999;i++){
        string s = to_string(i);
        string rev = s;
        reverse(rev.begin(),rev.end());
        rev.erase(0,1);
        long long palindrome = stoll(s+rev);
        if(palindrome > b){
            break;
        }
        if(palindrome >=a && isprime(palindrome)){
            cnt++;
        }
    }

    cout<< cnt<<endl;
    return 0;
}