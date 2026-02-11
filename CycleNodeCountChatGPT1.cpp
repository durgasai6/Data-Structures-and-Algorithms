#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> nextnode(n+1),indegree(n+1);
    queue<int> zerodegree;
    for(int i=1;i<=n;i++){
        cin>>nextnode[i];

        indegree[nextnode[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            zerodegree.push(i);
        }
    }
    while(!zerodegree.empty()){
        int current=zerodegree.front();
        zerodegree.pop();
        int temp=nextnode[current];
        indegree[temp]--;
        if(indegree[temp]==0){
            zerodegree.push(temp);
        }
    }
    int answerr=0;
    for(int i=1;i<=n;i++){
        if(indegree[i]>=1){
            answerr++;
        }
    }

    cout<<answerr<<endl;
    return 0;
}