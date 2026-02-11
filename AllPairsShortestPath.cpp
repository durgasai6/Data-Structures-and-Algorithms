#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<long long>> distance(n,vector<long long>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>distance[i][j];
        }
    }
    vector<int> order(n);
    for(int i=0;i<n;i++){
        cin>>order[i];
        order[i]--;
    }
    vector<bool> nodes(n,false);
    vector<long long> answer;
    for(int i=n-1;i>=0;i--){
        int k=order[i];
        nodes[k]=true;
        for(int i=0;i<n;i++){
            if(!nodes[i]){
                continue;
            }
            for(int j=0;j<n;j++){
                if(!nodes[j]){
                    continue;
                }
                distance[i][j]=min(distance[i][j],distance[i][k]+distance[k][j]);
            }
        }
        long long sum=0;
        for(int i=0;i<n;i++){
            if(!nodes[i]){
                continue;
            }
            for(int j=0;j<n;j++){
                if(!nodes[j]){
                    continue;
                }
                sum+=distance[i][j];
            }
        }
        answer.push_back(sum);
    }
    reverse(answer.begin(),answer.end());
    for(int i=0;i<n;i++){
        cout<<answer[i]<<" ";
    }
    cout<<endl;
    return 0;
}