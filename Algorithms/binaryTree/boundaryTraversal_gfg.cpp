
/*
Problem Statement: Boundary Traversal of Binary Tree

Given a binary tree, print the boundary nodes in anticlockwise direction starting from the root.
The boundary includes:
1. Left boundary - nodes on the path from root to the leftmost node.
2. Leaf nodes - all leaf nodes from left to right.
3. Right boundary - nodes on the path from rightmost node to root (excluding root).

Key Points:
- Left boundary excludes leaf nodes
- Right boundary excludes leaf nodes
- For nodes having both children, left child will be in left boundary and right child in right boundary
- For nodes having single child, the child is in left boundary if it is left child, else in right boundary
- Print root node before any of these

Time Complexity: O(n) where n is number of nodes
Space Complexity: O(n) for recursion stack and temporary storage

Example:
    1
     / \
    2   3    => Output: 1 2 4 5 6 3
   / \     
  4   5
     /
    6

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    
    bool isLeaf(Node* root) {
        return !root->left && !root->right;
    }
    
    void left(Node* root, vector<int>& res) {
        Node* curr = root;
        while (curr && !isLeaf(curr)) {
            res.push_back(curr->data);
            if (curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    
    void bottom(Node* root, vector<int>& res) {
        if (!root) return;
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        bottom(root->left, res);
        bottom(root->right, res);
    }
    
    void right(Node* root, vector<int>& res) {
        vector<int> temp;
        Node* curr = root;
        while (curr && !isLeaf(curr)) {
            temp.push_back(curr->data);
            if (curr->right) curr = curr->right;
            else curr = curr->left;
        }
        for (int i = temp.size() - 1; i >= 0; i--) {
            res.push_back(temp[i]);
        }
    }

public:
    vector<int> boundaryTraversal(Node *root) {
        if (!root) return {};
        
        vector<int> res;
        if (!isLeaf(root)) res.push_back(root->data);
        
        left(root->left, res);
        bottom(root, res);
        right(root->right, res);
        
        return res;
    }
};

int main(){

}