/*
Fixing Two nodes of a BST

Given the root of a Binary search tree(BST), where exactly two nodes were swapped by mistake. Your task is to fix (or correct) the BST by swapping them back. Do not change the structure of the tree.
Note: It is guaranteed that the given input will form BST, except for 2 nodes that will be wrong. All changes must be reflected in the original linked list.
*/

#include<bits/stdc++.h>
using namespace std;

// Using 1 pass and pointers


// Using Naive Approach where we used Inorder Traversal(Generaly stores a BST in sorted order) and store the Nodes and there after check for meistakes nodes
/*
class Solution {
  public:
    
    void inorder(Node* root , vector<Node*>&temp){
        if(!root) return;
        
        inorder(root->left , temp);
        temp.push_back(root);
        inorder(root->right , temp);
    }
    
    void correctBST(Node* root) {
        vector<Node*>temp;
        inorder(root, temp);
        Node *first = NULL, *second = NULL;
        
        for(int i = 1; i < temp.size(); i++) {
            if(temp[i]->data < temp[i-1]->data) {
                if(first == NULL) {
                    first = temp[i-1];
                }
                second = temp[i];
            }
        }
        
        if(first && second) {
            int t = first->data;
            first->data = second->data;
            second->data = t;
        }
    }
};
*/

int main(){
}
