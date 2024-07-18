#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};
/*
class Solution{
    void helper(TreeNode* root, vector<TreeNode*>curr, unordered_map<TreeNode* , vector<TreeNode*>> &uM, vector<TreeNode*>&uS){
        if(root == nullptr) return;
        curr.push_back(root);
        if(root->left == nullptr && root->right == nullptr){
            uM.insert({root, curr});
            uS.push_back(root);
            return;
        }
        helper(root->left, curr, uM, uS);
        helper(root->right, curr, uM, uS);
    }

public:
    int countPairs(TreeNode* root, int distance){
        if(root == nullptr) return 0;
        unordered_map<TreeNode* , vector<TreeNode*>>uM;
        vector<TreeNode*>uS;

        helper(root, {}, uM, uS); 
        int count = 0;
        for(int i = 0; i < uS.size() - 1; i++){
            for(int j = i + 1; j < uS.size(); j++){

                vector<TreeNode*>temp1 = uM[uS[i]];
                vector<TreeNode*>temp2 = uM[uS[j]];

                for(int k = 0; k< min(temp1.size(), temp2.size()); k++){
                    if(temp1[k] != temp2[k]){
                        int dis =temp1.size() - k + temp2.size() - k;
                        if(dis <= distance) count++;
                        break;
                    }
                }
            }
        }

        return count;      
    }
};
*/


class Solution {
public:
    int count = 0 ;
    vector<int> helper(TreeNode* root , int d){
        if(root == NULL)
            return {0};
        // leaf found
        if(root->left == NULL and root->right == NULL)
            return {1};
        
        vector<int> left = helper(root->left, d);
        vector<int> right = helper(root->right , d);
        
        // processing 
        for(int x : left){
            for(int y : right){
                if(x > 0 and y > 0 )
                    if(x+y <= d)
                        count+=1;
                // pair has been found
            }
        }
        
        vector<int> ans;
        for(int x : left){
            if(x > 0 and x < d)
                ans.push_back(x+1);
        }
        
        for(int x : right){
            if( x > 0 and x < d )
                ans.push_back(x+1);
        }
        return ans;
        
    }
    int countPairs(TreeNode* root, int distance) {
       helper(root , distance); 
        return count;
    }
};
