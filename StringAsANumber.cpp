#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<char> stack;
        for(int i=0;i<n;i++){
            while(!stack.empty() && k>0 && s[i]<stack.back()){
                stack.pop_back();
                k--;
            }
            stack.push_back(s[i]);
        }
        while(k>0 && !stack.empty()){
            stack.pop_back();
            k--;
        }
        string result;
        for(int i=0;i<stack.size();i++){
            result.push_back(stack[i]);
        }
        if(result.empty()){
            cout<<"0"<<endl;
        }
        else{
            cout<<result;
        }
    }
    return 0;
}

/*use a stack to store and compare the numbers
and print the result of the stack in a new string
easy*/