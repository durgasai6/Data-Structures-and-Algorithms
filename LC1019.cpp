#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int data){
        val=data;
        next=nullptr;
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    Node* head=nullptr;
    Node* tail=nullptr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;

        Node* newnode= new Node(x);
        if(head==nullptr){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    
    vector<int> nums;
    
    while(head!=nullptr){
        nums.push_back(head->val);
        head=head->next;
    }

    stack<int> st;
    vector<int> ans(n,0);
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[st.top()]<nums[i]){
            ans[st.top()]=nums[i];
            st.pop();
        }
        st.push(i);
    }
    for(int x:ans){
        cout<<x<<" ";
    }
    
    return 0;
}













/*You are given the head of a linked list with n nodes.

For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.

 

Example 1:


Input: head = [2,1,5]
Output: [5,5,0]
Example 2:


Input: head = [2,7,4,3,5]
Output: [7,0,5,5,0]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 104
1 <= Node.val <= 109*/