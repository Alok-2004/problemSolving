/*
Remove Half Nodes
You are given a binary tree and you need to remove all the half nodes (which have only one child).
Return the root node of the modified tree after removing all the half-nodes.

Note: The output will be judged by the inorder traversal of the resultant tree, inside the driver code
*/

class Node{
public:
	int val;
	Node* left;
	Node* right;
	
	Node(int data){
		val = data;
		left = nullptr;
		right = nullptr;	
	}
};

class Solution {
public:
    void helper(Node* root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) return;
        
        if (root->left) helper(root->left);
        if (root->right) helper(root->right);

        if (root->left == nullptr && root->right != nullptr) {
            *root = *root->right;
        } else if (root->right == nullptr && root->left != nullptr) {
            *root = *root->left;
        }
    }
    
    Node* RemoveHalfNodes(Node* root) {
        if (root == nullptr) return nullptr;
        helper(root);
        return root;
    }
};

