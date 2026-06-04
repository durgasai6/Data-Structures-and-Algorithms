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
        Node* newnode=new Node(x);
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
    Node* temp=head;
    while(temp!=nullptr){
        nums.push_back(temp->val);
        temp=temp->next;
    }
    int maxi=0;
    vector<int> fnums;
    for(int i=nums.size()-1;i>=0;i--){
        if(nums[i]>=maxi){
            fnums.push_back(nums[i]);
            maxi=nums[i];
        }
    }
    
    reverse(fnums.begin(),fnums.end());
    temp=head;
    Node* newhead=nullptr;
    Node* prev=nullptr;
    int idx=0;
    while(temp!=nullptr && idx<fnums.size()){
        if(temp->val==fnums[idx]){
            if(newhead==nullptr){
                newhead=temp;
            }
            if(prev!=nullptr){
                prev->next=temp;
            }
            prev=temp;
            idx++;
        }
        temp=temp->next;
        
    }
    if(prev!=nullptr){
        prev->next=nullptr;
    }
    head=newhead;
    temp=head;
    while(temp!=nullptr){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    return 0;
}















/*You are given the head of a linked list.

Remove every node which has a node with a greater value anywhere to the right side of it.

Return the head of the modified linked list.

 

Example 1:


Input: head = [5,2,13,3,8]
Output: [13,8]
Explanation: The nodes that should be removed are 5, 2 and 3.
- Node 13 is to the right of node 5.
- Node 13 is to the right of node 2.
- Node 8 is to the right of node 3.
Example 2:

Input: head = [1,1,1,1]
Output: [1,1,1,1]
Explanation: Every node has value 1, so no nodes are removed.
 

Constraints:

The number of the nodes in the given list is in the range [1, 105].
1 <= Node.val <= 105*/