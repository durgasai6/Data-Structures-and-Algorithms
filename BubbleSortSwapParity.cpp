#include<bits/stdc++.h>
using namespace std;

long long solve(vector<long long> &a, int low, int high){
    long long answer=0;
    if(low>=high){
        return 0;
    }
    int mid= low+(high-low)/2;
    answer+=solve(a,low,mid);
    answer+=solve(a,mid+1,high);
    vector<long long> ans;
    int i=low,j=mid+1;
    while(i<=mid && j<=high){
        if(a[i]<=a[j]){
            ans.push_back(a[i]);
            i++;
        }
        else{
            ans.push_back(a[j]);
            answer+=(mid-i+1);
            j++;
        }
    }
    while(i<=mid){
        ans.push_back(a[i]);
        i++;
    }
    while(j<=high){
        ans.push_back(a[j]);
        j++;
    }

    for(int k=low;k<=high;k++){
        a[k]=ans[k-low];
    }
    return answer;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        long long result=solve(a,0,n-1);
        cout<<result%2<<endl;
    }
    return 0;
}