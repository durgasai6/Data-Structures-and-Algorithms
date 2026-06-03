#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int data;
    ListNode* next;
    ListNode(int val){
        data=val;
        next=nullptr;
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,left,right;
    cin>>n>>left>>right;
    ListNode* head=nullptr;
    ListNode* tail=nullptr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ListNode* newnode=new ListNode(x);
        if(head==nullptr){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    if(left==right){
        ListNode* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        return 0;
    }
    ListNode* prevleft=nullptr;
    ListNode* curr=head;
    for(int i=1;i<left;i++){
        prevleft=curr;
        curr=curr->next;
    }

    ListNode* tailRev=curr;
    ListNode* prev=nullptr;

    for(int i=0;i<=right-left;i++){
        ListNode* nextnode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextnode;
    }
    tailRev->next=curr;


    ListNode* temp=head;
    if(prevleft!=nullptr){
        prevleft->next=prev;
    }
    else{
        head=prev;
    }
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}









/*Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
 */