#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        set<int> temp;
        for(int i=0;i<n;i++){
            temp.insert(a[i]);
        }
        int distinct=temp.size();
        unordered_map<int,int> freq;
        int left=0,currentdistinct=0,answer=n;
        for(int right=0;right<n;right++){
            freq[a[right]]++;
            if(freq[a[right]]==1){
                currentdistinct++;
            }
            while(currentdistinct==distinct){
                answer=min(answer,right-left+1);
                freq[a[left]]--;
                if(freq[a[left]]==0){
                    currentdistinct--;
                }
                left++;
            }
        }
        cout<<answer<<endl;
    }
    return 0;
}





/*Given an array of N integers, find the length of the smallest sub-array that contains all the distinct elements of the array.

Input Format

The first line contains T, the number of test cases (1<=T<=10).

The first line contains an integer N, 1<=N<=10^5.

Next line contains N space-separated integers (0<=Ai<=1e5).

 

Output Format

For each test case print length of the smallest sub-array that contains all the distinct elements of array in a newline.*/