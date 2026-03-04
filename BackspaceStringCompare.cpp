#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;
    cin>>s;
    cin>>t;
    int n=s.size();
    int m=t.size();
    stack<char> st1,st2;
    for(int i=0;i<n;i++){
        if(s[i]!='#'){
            st1.push(s[i]);
        }
        else{
            if(!st1.empty()){
                st1.pop();
            }
            else{
                continue;
            }
        }
    }
    for(int i=0;i<m;i++){
        if(t[i]!='#'){
            st2.push(t[i]);
        }
        else{
            if(!st2.empty()){
                st2.pop();
            }
            else{
                continue;
            }
        }
    }
    if(st1.size()!=st2.size()){
        cout<<"false"<<endl;
        return 0;
    }
    while(!st1.empty()){
        if(st1.top()!=st2.top()){
            cout<<"false"<<endl;
            return 0;
        }
        st1.pop();
        st2.pop();
    }
    cout<<"true"<<endl;
    return 0;
}