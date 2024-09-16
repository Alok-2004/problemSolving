/*
Binary Tree to DLL
Given a Binary Tree (BT), convert it to a Doubly Linked List (DLL) in place. The left and right pointers in nodes will be used as 
previous and next pointers respectively in converted DLL. The order of nodes in DLL must be the same as the order of the given Binary Tree. 
The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.
*/
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void solve(Node* root, Node*& curr) {
        if (root == nullptr) return;

        if (root->left) solve(root->left, curr);

        curr->right = root;
        root->left = curr;
        curr = curr->right;

        if (root->right) solve(root->right, curr);
    }

    Node* bToDLL(Node* root) {
        Node* dummy = new Node(INT_MIN);
        Node* curr = dummy;

        solve(root, curr);

        Node* head = dummy->right;
        if (head != nullptr) {
            head->left = nullptr;
        }

        delete dummy;

        return head;
    }
};


int main(){
	
}
