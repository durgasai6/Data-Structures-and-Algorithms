#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    long long l;
    cin>>l>>n;
    priority_queue<long long, vector<long long>, greater<long long>> mana;
    for(int i=0;i<n;i++){
        long long lengths;
        cin>>lengths;
        mana.push(lengths);

    }
    long long totalmana=0;
    while(mana.size()>1){
        long long a=mana.top();
        mana.pop();
        long long b= mana.top();
        mana.pop();
        long long currentmana=a+b;
        totalmana+=currentmana;
        mana.push(currentmana);
    }
    cout<<totalmana<<endl;
    return 0;
}