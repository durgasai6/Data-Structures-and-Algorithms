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
    vector<int> ans;
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

    if(head==nullptr || head->next==nullptr){
        ans.push_back(-1);
        ans.push_back(-1);
        for(int x:ans){
            cout<<x<<" ";
        }
        return 0;
    }

    Node* prev=head;
    Node* curr=head->next;

    int pos=2;
    while(curr!=nullptr && curr->next!=nullptr){
        if(curr->val > prev->val && curr->val > curr->next->val){
            nums.push_back(pos);
        }

        if(curr->val < prev->val && curr->val < curr->next->val){
            nums.push_back(pos);
        }
        prev=curr;
        curr=curr->next;
        pos++;

    }
    int minans=INT_MAX; 
    if(nums.size() < 2){
        ans.push_back(-1);
        ans.push_back(-1);
        for(int x:ans){
            cout<<x<<" ";
        }
        return 0;
    }

    for(int i=1;i<nums.size();i++){
        minans=min(minans,nums[i]-nums[i-1]);
    }
    int maxans=nums.back()-nums.front();

    ans.push_back(minans);
    ans.push_back(maxans);
    
    

    for(int x:ans){
        cout<<x<<" ";
    }


    return 0;
}















/*A critical point in a linked list is defined as either a local maxima or a local minima.

A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.

A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].

 

Example 1:


Input: head = [3,1]
Output: [-1,-1]
Explanation: There are no critical points in [3,1].
Example 2:


Input: head = [5,3,1,2,5,1,2]
Output: [1,3]
Explanation: There are three critical points:
- [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less than 3 and 2.
- [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is greater than 2 and 1.
- [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less than 5 and 2.
The minimum distance is between the fifth and the sixth node. minDistance = 6 - 5 = 1.
The maximum distance is between the third and the sixth node. maxDistance = 6 - 3 = 3.
Example 3:


Input: head = [1,3,2,2,3,2,2,2,7]
Output: [3,3]
Explanation: There are two critical points:
- [1,3,2,2,3,2,2,2,7]: The second node is a local maxima because 3 is greater than 1 and 2.
- [1,3,2,2,3,2,2,2,7]: The fifth node is a local maxima because 3 is greater than 2 and 2.
Both the minimum and maximum distances are between the second and the fifth node.
Thus, minDistance and maxDistance is 5 - 2 = 3.
Note that the last node is not considered a local maxima because it does not have a next node.
 

Constraints:

The number of nodes in the list is in the range [2, 105].
1 <= Node.val <= 105*/