#include<bits/stdc++.h>
using namespace std;
long long power(long long a, long long p){
    long long res=1;
    while(p>0){
        if(p%2==1){
            res=res*a;
        }
        a=a*a;
        p=p/2;
    }
    return res;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int x,y,bound;
    cin>>x>>y>>bound;
    vector<int> xbound,ybound;
    long long temp=1;
    
    int i=0;
    while(temp<=bound){
        xbound.push_back(temp);
        if(x==1){
            break;
        }
        i++;
        temp=power(x,i);
    }
    int j=0;
    temp=1;
    while(temp<=bound){
        ybound.push_back(temp);
        if(y==1){
            break;
        }
        j++;
        temp=power(y,j);
    }
    set<int> st;
    
    for(int m=0;m<xbound.size();m++){
        for(int n=0;n<ybound.size();n++){
            int sum=xbound[m]+ybound[n];
            if(sum<=bound){
                st.insert(sum);
            }
        }
    }
    vector<int> ans(st.begin(),st.end());
    for(int x:ans){
        cout<<x<<" ";
    }
    return 0;
}
















/*Given three integers x, y, and bound, return a list of all the powerful integers that have a value less than or equal to bound.

An integer is powerful if it can be represented as xi + yj for some integers i >= 0 and j >= 0.

You may return the answer in any order. In your answer, each value should occur at most once.

 

Example 1:

Input: x = 2, y = 3, bound = 10
Output: [2,3,4,5,7,9,10]
Explanation:
2 = 20 + 30
3 = 21 + 30
4 = 20 + 31
5 = 21 + 31
7 = 22 + 31
9 = 23 + 30
10 = 20 + 32
Example 2:

Input: x = 3, y = 5, bound = 15
Output: [2,4,6,8,10,14]
 

Constraints:

1 <= x, y <= 100
0 <= bound <= 106*/