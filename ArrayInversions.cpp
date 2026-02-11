#include<bits/stdc++.h>
using namespace std;

bool compare(pair<long long, long long> &A, pair<long long, long long> &B){
    return A.first*B.second <B.first*A.second;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int m;
        cin>>m;
        vector<pair<long long, long long>> arr(m);
        long long answer=0;
        for(int i=0;i<m;i++){
            string s;
            cin>>s;
            long long ones=0,zeroes=0,internalinv=0;
            for(char c : s){
                if(c =='1'){
                    ones++;
                    internalinv++;
                }
                else{
                    zeroes++;
                    answer+=internalinv;
                }
            }
            arr[i] = {ones,zeroes};
        }
        sort(arr.begin(),arr.end(),compare);
        long long onesseen=0;
        for(auto &p :arr){
            long long ones=p.first;
            long long zeroes=p.second;
            answer+=onesseen*zeroes;
            onesseen+=ones;
        }
        cout<<answer<<endl;
    }
    return 0;
}