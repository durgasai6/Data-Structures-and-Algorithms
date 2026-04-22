#include<bits/stdc++.h>
using namespace std;

class MinStack{
private:
stack<int> st,minstack;

public:
    void push(int val){
        st.push(val);
        if(minstack.empty()){
            minstack.push(val);
        }
        else{
            int temp=min(minstack.top(),val);
            minstack.push(temp);
        }
    }

    void pop(){
        if(!st.empty()){
            st.pop();
            minstack.pop();
        }
    }

    int top(){
        return st.top();
    }

    int getmin(){
        return minstack.top();
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    MinStack m;
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        if(s=="push"){
            int val;
            cin>>val;
            m.push(val);
        }
        else if(s=="pop"){
            m.pop();
        }
        else if(s=="getmin"){
            cout<<m.getmin()<<endl;
        }
        else if(s=="top"){
            cout<<m.top()<<endl;
        }
    }

    return 0;
}












/*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.*/