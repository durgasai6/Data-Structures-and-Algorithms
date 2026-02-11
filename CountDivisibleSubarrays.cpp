#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<long long> freq(n,0);
    long long pref=0,answer=0;;
    freq[0]=1;
    for(int i=0;i<n;i++){
        pref+=a[i];
        long long remainder=((pref %n)+n)%n;
        freq[remainder]++;
    }
    for(int i=0;i<n;i++){
        if(freq[i]>=2){
            answer+=(freq[i]*(freq[i]-1))/2;
        }
    }
    cout<<answer<<endl;
    return 0;
}