#include<bits/stdc++.h>
using namespace std;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin>>n;
  vector<int> nums(n);
  for(int i=0;i<n;i++){
    cin>>nums[i];
  }
  vector<int> ans;
  vector<int> pos,neg;
  for(int i=0;i<n;i++){
    if(nums[i]>=0){
      pos.push_back(nums[i]);
    }
    else{
      neg.push_back(nums[i]);
    }
  }
  bool start=(pos.size()<neg.size());
  int i=0,j=0;
  while(i<pos.size() && j<neg.size()){
    if(start){
      ans.push_back(neg[j]);
      ans.push_back(pos[i]);
    }
    else{
      ans.push_back(pos[i]);
      ans.push_back(neg[j]);
    }
    i++;
    j++;
  }
  while(i<pos.size()){
    ans.push_back(pos[i]);
    i++;
  }
  while(j<neg.size()){
    ans.push_back(neg[j]);
    j++;
  }
  
  for(int x:ans){
    cout<<x<<" ";
  }
  return 0;
}









/*You are given a zero indexed array of n
 integers. You need to rearrange the elements of the array in such a way that positive and negative numbers are placed alternatively at the begining of the array and the length of the prefix k
 where ai∗ai−1<0
 for each i(1≤i≤k)
 is maximum. If there are more positive of negative numbers they are placed at the end of the array. If there are multiple solutions, output any.

Input
The first line contains a single integer n(1≤n≤105)
.

The next line contains n
 space separated integers a1,a2,...,an(−109≤ai≤109)
 and ai!=0
.

Output
Output n
 integers - the resultant array.

Example
Input
5
1 2 3 -4 5
Output
1 -4 2 3 5 */