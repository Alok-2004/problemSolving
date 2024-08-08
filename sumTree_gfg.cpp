/*
Sum Tree
Given a Binary Tree. Check for the Sum Tree for every node except the leaf node. Return true if it is a Sum Tree otherwise, return false.

A SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree. 
An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.
*/

// TC O(n*n)
/*
class Solution {
  public:
  
    int sum(Node*root , int s){
        if(root == nullptr) return 0;
        s += root->data;
        return root->data + sum(root->left , s) + sum(root->right , s);
        
    }
    
    bool helper(Node* root){
        if(root == nullptr) return true;
        if(root->left == nullptr && root->right == nullptr) return true;
        
        int leftSum = sum(root->left , 0);
        int rightSum = sum(root->right , 0);
        
        bool temp = (root->data == (leftSum+rightSum));
        
        return (temp && helper(root->left) && helper(root->right)); 
    }
    
    bool isSumTree(Node* root) {
        if( root == nullptr) return true;
        else return helper(root);
    }
};
*/


//O(n)
class Solution {
public:
    pair<int , bool> helper(Node* root){
        if(root == nullptr) return  {0 , true};
        if(root->left == nullptr && root->right == nullptr) return {root->data , true};
        
        auto l = helper(root->left);
        auto r = helper(root->right);
        
        bool temp = (root->data == l.first + r.first );
        return {root->data + l.first + r.first , temp && l.second && r.second };
    }
    
    bool isSumTree(Node* root) {
        if( root == nullptr ) return true;
        else return helper(root).second;
    }
};

