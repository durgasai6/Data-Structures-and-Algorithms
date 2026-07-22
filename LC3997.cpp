#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data){
        val=data;
        left=nullptr;
        right=nullptr;
    }
};


int postorder(TreeNode* root,int &ans){
    if(root==nullptr){
        return INT_MIN;
    }

    int leftmax=postorder(root->left,ans);
    int rightmax=postorder(root->right,ans);

    int maxi=max(root->val, max(leftmax,rightmax));

    if(root->val==maxi){
        ans++;
    }
    return maxi;
}


int countDominantNodes(TreeNode* root){
    int ans=0;
    postorder(root,ans);
    return ans;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> root(n);
    for(int i=0;i<n;i++){
        cin>>root[i];
    }

    if(n==0){
        return 0;
    }

    TreeNode* r=new TreeNode(root[0]);

    queue<TreeNode*> q;
    q.push(r);

    int i=1;
    while(i<n){
        TreeNode* curr=q.front();
        q.pop();
        if(i<n){
            curr->left=new TreeNode(root[i]);
            q.push(curr->left);
            i++;
        }

        if(i<n){
            curr->right=new TreeNode(root[i]);
            q.push(curr->right);
            i++;
        }
    }


    cout<<countDominantNodes(r)<<endl;

    return 0;
}











/*You are given the root of a complete binary tree.

A node x is called dominant if its value is equal to the maximum value among all nodes in the subtree rooted at x.

Return the number of dominant nodes in the tree.

 

Example 1:



Input: root = [5,3,8,2,4,7,1]

Output: 5

Explanation:

The leaf nodes with values 2, 4, 7, and 1 are dominant.
The node with value 8 is dominant because its value is the maximum value in its subtree [8, 7, 1].
Thus, the answer is 5.
Example 2:



Input: root = [1,2,3,1,2]

Output: 4

Explanation:

The leaf nodes with values 1, 2, and 3 are dominant.
The node with value 2 whose subtree is [2, 1, 2] is dominant because its value is the maximum value in its subtree.
Thus, the answer is 4.
 

Constraints:

The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 109
The tree is guaranteed to be a complete binary tree.*/