#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n=s.size();
    int left=0,right=n-1;
    while(left<right && s[left]==s[right]){
        char c=s[left];
        while(left<=right && s[left]==c){
            left++;
        } 
        while(left<=right && s[right]==c){
            right--;
        }
    }
    cout<<right-left+1<<endl;
    return 0;
}