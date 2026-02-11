#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int num,den;
        cin>>num>>den;
        if(num==0){
            cout<<"0"<<endl;
            continue;
        }
        if((num<0 && den>0) || (num>0 && den <0)){
            cout<<"-";
        }
        if(num<0){
            num = -num;
        }
        if(den<0){
            den=-den;
        }

        int intgerpart = num/den;
        int remainder=num%den;

        
        cout<<intgerpart;
        if(remainder==0){
            cout<<endl;
            continue;
        }
        cout<<".";
        vector<int> rem;
        rem.assign(101,-1);
        string decimal="";
        int index=0;
        while(remainder!=0){
            if(rem[remainder] != -1){
                int start = rem[remainder];
                decimal.insert(start,"(");
                decimal.push_back(')');
                break;
            }
            rem[remainder] = index;
            remainder *= 10;
            int digit = remainder/den;
            decimal.push_back(char('0'+digit));
            remainder %=den;
            index++;
        }
        cout<<decimal<<endl;
    }
    return 0;
}