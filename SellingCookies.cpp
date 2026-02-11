#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        long long totalcookies = 0;
        long long maxstack = 0;
        for(int i=0;i<n;i++){
            long long presentC;
            cin>>presentC;
            totalcookies += presentC;
            maxstack = max(maxstack, presentC);
        }
        if(2*maxstack <= totalcookies){
            cout<<0<<endl;
        }
        else{
            cout<<2*maxstack - totalcookies;
        }
    }
    return 0;
}


/*suppose we have 3 different cookies which are of stacks 2,3,6.. 
now total cookies on iteration 1 is 2 and max cookies is 2
iteration 2 total cookies is 5 and max cookies is 3
iteration 3 total cookies id 11 and max cookies is 11
2 times max cookies =12
total cookies is equal to 11
so left over cookies will be 1
all others can be paired up
if 2 times max cookies is 8 for example
then max stack will be paired up fully first and the other cookies left over will be 2 from 2 different types
so those 2 will be paired up and we get 0 left over*/