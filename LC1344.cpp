#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int hour,minutes;
    cin>>hour>>minutes;
    if(hour==12){
        hour=0;
    }
    double minutedegree=minutes*6.0;
    double hours=minutes*0.5;
    hours+=hour*30;
    double result=abs(minutedegree-hours);
    cout<<min(result,360-result)<<endl;
    return 0;
}












/*Given two numbers, hour and minutes, return the smaller angle (in degrees) formed between the hour and the minute hand.

Answers within 10-5 of the actual value will be accepted as correct.

 

Example 1:


Input: hour = 12, minutes = 30
Output: 165
Example 2:


Input: hour = 3, minutes = 30
Output: 75
Example 3:


Input: hour = 3, minutes = 15
Output: 7.5
 

Constraints:

1 <= hour <= 12
0 <= minutes <= 59*/