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

Node* solve(Node* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }

    Node* odd=head;
    Node* even=head->next;
    Node* evenhead=even;

    while(even!=nullptr && even->next!=nullptr){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }

    odd->next=evenhead;

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

    head=solve(head);

    Node* temp= head;
    while(temp!=nullptr){
        cout<<temp->val<<" ";
        temp=temp->next;
    }

    return 0;
}










/*Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
Example 2:


Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
 

Constraints:

The number of nodes in the linked list is in the range [0, 104].
-106 <= Node.val <= 106*/