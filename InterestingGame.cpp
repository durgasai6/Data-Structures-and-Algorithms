#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<int> A(n), B(n);
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        for(int i=0;i<n;i++){
            cin>>B[i];
        }
        int sumA=0, sumB=0;
        vector<pair<int, int>> sumi;
        for(int i=0;i<n;i++){
            sumi.push_back({A[i],B[i]});
        }
        sort(sumi.begin(), sumi.end(), [](pair<int,int> &p1, pair<int,int> &p2){
            return (p1.first+p1.second) >(p2.first+p2.second);
        });

        for(int i=0;i<n;i++){
            if(i%2==0){
                sumA = sumi[i].first;
            }
            else{
                sumB=sumi[i].second;
            }
        }

        if(sumA>sumB){
            cout<<"Alice"<<endl;
        }
        else if(sumB>sumA){
            cout<<"Bob"<<endl;
        }
        else{
            cout<<"Tie"<<endl;
        }
        
    }


    return 0;
}