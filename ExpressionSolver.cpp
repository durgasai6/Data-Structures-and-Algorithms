#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        long long leftside=0,rightside=0,leftcoefficient=0,rightcoefficient=0;
        long long number=0;
        int sign=1;
        bool left=true;
        for(int i=0;i<=s.size();i++){
            if(i==s.size()||s[i]=='+'||s[i]=='-'||s[i]=='='){
                
                if(left){
                    leftside +=sign*number;
                }
                else{
                    rightside+=sign*number;
                        
                }
                number=0;
                
                if(i<s.size()){
                    if(s[i]=='+'){
                        sign=1;
                    }
                    else if(s[i]=='-'){
                        sign=-1;
                    }
                    else if(s[i]=='='){
                        left=false;
                        sign=1;
                    }
                }
            }
            else if(isdigit(s[i])){
                number = number*10 + (s[i]-'0');
            }
            else if(s[i]=='X'){
                if(left){
                    leftcoefficient+=sign;
                }
                else{
                    rightcoefficient+=sign;
                }
            }
        }
        long long answer= (rightside-leftside)/(leftcoefficient-rightcoefficient);
        cout<<answer<<endl;
    }
    return 0;
}