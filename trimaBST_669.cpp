#include<iostream>
#include<climits>
using namespace std;

class TreeNode{
  public:
	int val;
	TreeNode *left;
	TreeNode *right;
	
	TreeNode(int val){
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
};

void trim(TreeNode* root, int lo, int hi){
    if(root == NULL) return;
    while(root->left){
        if(root->left->val < lo)   root->left = root->left->right;
        else if(root->left->val > hi)   root->left = root->left->left;
        else break;
    }

    while(root->right){
        if(root->right->val > hi) root->right = root->right->left;
        else if(root->right->val < lo) root->right = root->right->right;
        else break;
    }

    trim(root->left, lo, hi);
    trim(root->right, lo, hi);
    return;
}

TreeNode* trimBST(TreeNode* root, int low, int high) {
  //to check the root we will use dummy value
  TreeNode* dummy = new TreeNode(INT_MAX);
  dummy->left = root;
  trim(dummy, low, high);
  return dummy->left;  
}