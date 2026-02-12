#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &heights){
    stack<int> s;
    heights.push_back(0);
    int n=heights.size();
    int maxarea=0;

    for(int i=0;i<n;i++){
        while(!s.empty() && heights[i]<heights[s.top()]){
            int currentheight=heights[s.top()];
            s.pop();
            int width;
            if(s.empty()){
                width=1;
            }
            else{
                width=i-s.top()-1;
            }
            maxarea=max(maxarea,currentheight*width);
        }
        s.push(i);
    }
    return maxarea;
}

int main(){
    int n;
    cin>>n;
    vector<int> heights(n);
    for(int i=0;i<n;i++){
        cin>>heights[i];
    }
    
    
  
    cout<<solve(heights)<<endl;
    return 0;
}