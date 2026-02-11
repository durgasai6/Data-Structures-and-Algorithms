#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        unordered_map<int, int> freq;
        int distinct=0;
        for(int i=0;i<d;i++){
            if(freq[a[i]]==0){
                distinct++;
            }
            freq[a[i]]++;
        }
        int answer= distinct;
        for(int i=d;i<n;i++){
            int remove = a[i-d];
            int join = a[i];
            freq[remove]--;
            if(freq[remove]==0){
                distinct--;
            }
            if(freq[join]==0){
                distinct++;
            }
            freq[join]++;
            answer=min(answer,distinct);
        }
        cout<<answer<<endl;
    }
    return 0;
}