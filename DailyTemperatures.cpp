#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> temperatures(n);
    for(int i=0;i<n;i++){
        cin>>temperatures[i];
    }
    vector<int> answer(n,0);
    stack<int> st;
    st.push(0);
    for(int i=1;i<n;i++){
        while(!st.empty() && temperatures[i]>temperatures[st.top()]){
            int temp=st.top();
            st.pop();
            answer[temp]=i-temp;
        }
        st.push(i);
    }
    for(int i=0;i<n;i++){
        cout<<answer[i]<<" ";
    }
    return 0;
}