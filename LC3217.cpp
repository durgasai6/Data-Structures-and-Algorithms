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



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    ListNode* head=nullptr;
    ListNode* tail=nullptr;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        ListNode* newnode= new ListNode(x);
        if(head==nullptr){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    ListNode* prev=nullptr;
    ListNode* temp=head;
    unordered_set<int> mp;
    for(int x:nums){
        mp.insert(x);
    }

    while(temp!=nullptr){
        if(mp.find(temp->val)!=mp.end()){
            if(prev==nullptr){
                ListNode* del=head;
                head=head->next;
                temp=head;
            }
            else{
                ListNode* del=temp;
                prev->next=temp->next;
                temp=temp->next;
            }
        }
        else{
            prev=temp;
            temp=temp->next;
        }
    }
    temp=head;
    while(temp!=nullptr){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    return 0;
}










/*You are given an array of integers nums and the head of a linked list. Return the head of the modified linked list after removing all nodes from the linked list that have a value that exists in nums.

 

Example 1:

Input: nums = [1,2,3], head = [1,2,3,4,5]

Output: [4,5]

Explanation:



Remove the nodes with values 1, 2, and 3.

Example 2:

Input: nums = [1], head = [1,2,1,2,1,2]

Output: [2,2,2]

Explanation:



Remove the nodes with value 1.

Example 3:

Input: nums = [5], head = [1,2,3,4]

Output: [1,2,3,4]

Explanation:



No node has value 5.

 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105
All elements in nums are unique.
The number of nodes in the given list is in the range [1, 105].
1 <= Node.val <= 105
The input is generated such that there is at least one node in the linked list that has a value not present in nums.*/