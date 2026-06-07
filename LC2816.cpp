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


Node* reverselist(Node* head){
    Node* prev=nullptr;
    Node* curr=head;
    while(curr!=nullptr){
        Node* nextnode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextnode;
    }
    return prev;
}

Node* doubleit(Node* head){
    head= reverselist(head);
    Node* curr=head;
    int carry=0;
    while(curr!=nullptr){
        curr->val=((curr->val)*2)+carry;
        if(curr->val >9){
            carry=curr->val/10;
            curr->val=(curr->val)%10;
        }
        else{
            carry=0;
        }
        curr=curr->next;
    }
    curr=head;
    while(curr->next!=nullptr){
        curr=curr->next;
    }
    if(carry!=0){
        Node* last=new Node(carry);
        curr->next=last;   
    }
    head=reverselist(head);
    return head;
}

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

    head=doubleit(head);
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    return 0;
}













/*You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.

Return the head of the linked list after doubling it.

 

Example 1:


Input: head = [1,8,9]
Output: [3,7,8]
Explanation: The figure above corresponds to the given linked list which represents the number 189. Hence, the returned linked list represents the number 189 * 2 = 378.
Example 2:


Input: head = [9,9,9]
Output: [1,9,9,8]
Explanation: The figure above corresponds to the given linked list which represents the number 999. Hence, the returned linked list reprersents the number 999 * 2 = 1998. 
 

Constraints:

The number of nodes in the list is in the range [1, 104]
0 <= Node.val <= 9
The input is generated such that the list represents a number that does not have leading zeros, except the number 0 itself.*/