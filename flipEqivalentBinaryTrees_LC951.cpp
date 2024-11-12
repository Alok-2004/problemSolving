/*
951. Flip Equivalent Binary Trees
For a binary tree T, we can define a flip operation as follows: 
choose any node, and swap the left and right child subtrees.

A binary tree X is flip equivalent to a binary tree Y if and only if we can 
make X equal to Y after some number of flip operations.

Given the roots of two binary trees root1 and root2, 
return true if the two trees are flip equivalent or false otherwise.
*/

#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int _val){
		val = _val;
		left = nullptr;
		right = nullptr;
	}
};

class Solution {
public:

    bool solve(TreeNode* root1 , TreeNode* root2){
        if((root1 == nullptr and root2) or (root2 == nullptr and root1)) return false;
        if(!root1 and !root2) return true;
        if(root1->val != root2->val) return false;

        // if((root1->left and root2->left) and root1->left->val == root2->left->val){
        //     return (solve(root1->left , root2->left) and solve(root1->right , root2->right));
        // }
        
        // else if((root1->left and root2->left) and root1->left->val != root2->left->val){
        //     return (solve(root1->right , root2->left) and solve(root1->left , root2->right));
        // }
        
        // else if(root1->left and !root2->left){
        //     return solve(root1->left , root2->right) and solve(root1->right , root2->left);
        // }

        // else if(root1->right and !root2->right){
        //     return solve(root1->left , root2->right) and solve(root1->right , root2->left);    
        // }
        
        // else{
        //     return solve(root1->left , root2->left) and solve(root1->right , root2->right);
        // }

        return (solve(root1->left , root2->left) and solve(root1->right , root2->right)) or  (solve(root1->left , root2->right) and solve(root1->right , root2->left));
    } 

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return solve(root1 , root2);
    }
};

int main(){
	
}
