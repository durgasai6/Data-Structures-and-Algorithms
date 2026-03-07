#include<bits/stdc++.h>
using namespace std;

int days(string start,string end){
    unordered_map<string, int> monthdays={{"january",31},{"february",28},{"march",31},{"april",30},{"may",31},{"june", 30},{"july",31},{"august",31},{"september",30},{"october",31},{"november",30},{"december",31}};

    int totaldays=0;
    bool temp=false;
    vector<string> month={"january","february","march","april","may","june","july","august","september","october","november","december"};
    for(int i=0;i<12;i++){
        if(start==month[i]){
            temp=true;
        }
        if(temp){
            totaldays+=monthdays[month[i]];
        }
        if(month[i]==end){
            break;
        }
    }
    return totaldays;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string start,end;
    cin>>start>>end;
    int n;
    n=days(start,end);
    vector<long long> arr(n+1);
    arr[1]=1;
    for(int i=2;i<=n;i++){
        arr[i]=(arr[i-1])+(i-1)*2;
    }
    // for(int i=0;i<=n;i++){
    //     cout<<arr[i]<<" ";
    // }
    unordered_map<string, int> monthdays={{"january",31},{"february",28},{"march",31},{"april",30},{"may",31},{"june", 30},{"july",31},{"august",31},{"september",30},{"october",31},{"november",30},{"december",31}};


    vector<string> month={"january","february","march","april","may","june","july","august","september","october","november","december"};
    int startidx,endidx;
    for(int i=0;i<12;i++){
        if(month[i]==start){
            startidx=i;
        }
        if(month[i]==end){
            endidx=i;
        }
    }
    int j=endidx-startidx+1;
    vector<long long> sales(j,0);

    int mon=startidx, day=0,idx=0;



    long long corporate=0,retail=0;
    for(int i=1;i<=n;i++){
        sales[idx]+=arr[i];
        if(i%5==0){
            corporate+=arr[i];
        }
        else{
            retail+=arr[i];
        }
        day++;
        if(day==monthdays[month[mon]]){
            mon++;
            idx++;
            day=0;
        }
    }
    cout<<"monthly sale: [";
    for(int i=0;i<j;i++){
        cout<<sales[i];
        if(i!=j-1){
            cout<<", ";
        }
        
    }
    cout<<"]"<<endl;
    cout<<"retail: "<<retail<<endl;
    cout<<"corporate: "<<corporate<<endl;

    return 0;
}







/*Problem Statement: Super Wheels Sales Analysis
For hiring by: Ernst & Young
Year Asked: 2022
Round: 1
Difficulty: Easy
Company Type: Dream
A vehicle company named Super Wheels wants to analyze its vehicle sales between April 1 and September 30.
The sales follow a specific daily pattern, and vehicles are sold to two types of customers: Retail and Corporate.
Your task is to model the daily sales pattern and analyze the sales data for the given period.

1. Daily Sales Pattern
Vehicle sales follow an increasing pattern:
Day 1: 1 vehicle
Day 2: 3 vehicles
Day 3: 7 vehicles
The rule is:
Each day’s sales increase by 2 × (day number) compared to the previous day.
Example progression:
Day 1 → 1
Day 2 → 3  (+2)
Day 3 → 7  (+4)
Day 4 → 13 (+6)
Day 5 → 21 (+8)
and so on.

 

2. Customer Allocation
 
Vehicles sold each day are assigned to customers as follows:
Retail Customers: Days 1–4, 6–9, 11–14, etc.
Corporate Customers: Every 5th day
(Day 5, 10, 15, 20, etc.)

3. Sales Period
The sales simulation runs from:
April 1 to September 30
Your program must generate sales for each day in this period.

Queries to Answer
Your program should compute and display the following:
Total vehicles sold per month
(April, May, June, July, August, September)
Cumulative sales by customer type
Total Retail sales
Total Corporate sales

Monthly sale: [9020, 66681, 175550, 354113, 588597, 848990]
Retail: 1641095
Corporate: 401856
*/