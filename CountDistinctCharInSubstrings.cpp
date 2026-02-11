#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;

        long long numofsubstrings=n*(n+1)/2;
        string s;
        cin>>s;
        long long answer=0;
        
        for(char ch='a';ch<='z';ch++){
            long long noch=0;
            long long length=0;
            for(int i=0;i<n;i++){
                if(s[i] != ch){
                    length++;
                }
                else{
                    noch+=length*(length+1)/2;
                    length=0;
                }
            }
            noch +=length*(length+1)/2;

            long long withch = numofsubstrings - noch;
            answer+=withch;
        }
        cout<<answer<<endl;
    }
    return 0;
}