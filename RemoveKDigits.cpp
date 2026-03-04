#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string num;
    cin>>num;
    int k;
    cin>>k;
    int n=num.size();
    stack<char> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top()>num[i] && k>0){
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    while(k>0 && !st.empty()){
        st.pop();
        k--;
    }
    string ans="";
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    int m=0;
    while(m<ans.size() && ans[m]=='0'){
        m++;
    }
    ans=ans.substr(m);
    if(ans==""){
        cout<<0<<endl;
        return 0;
    }
    cout<<ans<<endl;

    return 0;
}







/*Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 

Constraints:

1 <= k <= num.length <= 105
num consists of only digits.
num does not have any leading zeros except for the zero itself.*/