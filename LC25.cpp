#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int data){
        val=data;
        next=nullptr;
    }
};

ListNode* reverselist(ListNode* head){
    ListNode* prev=nullptr;
    while(head){
        ListNode* nextnode=head->next;
        head->next=prev;
        prev=head;
        head=nextnode;
    }
    return prev;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
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
    int k;
    cin>>k;
    
    ListNode* start=head;
    ListNode* last=nullptr;

    while(start){
        ListNode* kth=start;
        for(int i=1;i<k && kth;i++){
            kth=kth->next;
        }
        if(!kth){
            break;
        }
        ListNode* nextgroup=kth->next;
        kth->next=nullptr;

        ListNode* newhead=reverselist(start);

        if(last==nullptr){
            head=newhead;
        }
        else{
            last->next=newhead;
        }

        start->next=nextgroup;
        last=start;
        start=nextgroup;
    }

    ListNode* temp=head;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }

    return 0;
}




/*Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000*/