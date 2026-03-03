#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> nums1(n),nums2(m);
    for(int i=0;i<n;i++){
        cin>>nums1[i];
    }
    for(int i=0;i<m;i++){
        cin>>nums2[i];
    }
    int p1=0, p2=0;
    vector<int> temp;
    while(p1<n && p2 <m){
        if(nums1[p1]<nums2[p2]){
            temp.push_back(nums1[p1]);
            p1++;
        }
        else if(nums1[p1]>nums2[p2]){
            temp.push_back(nums2[p2]);
            p2++;
        }
        else{
            temp.push_back(nums1[p1]);
            temp.push_back(nums2[p2]);
            p1++;
            p2++;
        }
    }
    if(p1==n-1){
        for(int i=p2;i<m;i++){
            temp.push_back(nums2[p2]);
        }
    }
    else{
        for(int i=p1;i<n;i++){
            temp.push_back(nums1[p1]);
        }
    }
    int mid=(n+m)/2;
    int answer=0;
    if(mid%2!=0){
        answer=temp[mid];
    }
    else{
        answer=(temp[mid]+temp[mid+1])/2;
    }
    cout<<answer<<endl;

    return 0;
}