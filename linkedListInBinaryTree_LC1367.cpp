/*
1367. Linked List in Binary Tree
Given a binary tree root and a linked list with head as the first node. 

Return True if all the elements in the linked list starting from the head correspond to 
some downward path connected in the binary tree otherwise return False.

In this context downward path means a path that starts at some node and goes downwards.
*/
#include<bits/stdc++.h>
using namespace std;

class ListNode{
public:
	int val;
	ListNode* next;
	
	ListNode(int x){
		val = x;
		next = nullptr;
	}	
};

class TreeNode{
public:
	int val;
	TreeNode* right;
	TreeNode* left;
	
	ListNode(int x){
		val = x;
		left = nullptr;
		right = nullptr;
	}	
};

class Solution {
public:

    bool helper(ListNode* curr , TreeNode*root , bool found , ListNode* base){
        if(curr == nullptr) return true;
        if(root == nullptr and curr != nullptr) return false;
        bool check1 = false;
        bool check2 = false;
        bool check3 = false;
        if(found){
            if(root->val == curr->val){
                check1 = helper(curr->next , root->left , true , base) or helper(curr->next , root->right , true , base);
            }else{
                check1 = helper(base , root , false , base);
            } 
        }else if(root->val == curr->val and curr == base){
            check2 = helper(curr->next , root->left , true , base) or helper(curr->next , root->right , true , base);
        }else{
            check3 = helper(base , root->left , false , base) or helper(base , root->right , false , base);
        }

        return check1 or check2 or check3;
    }


    bool isSubPath(ListNode* head, TreeNode* root ) {
        if (root == nullptr) return false;
        return helper(head , root , false , head) or isSubPath(head , root->left) or isSubPath(head , root->right);
    }
};

int main(){
	
}
