#include<bits/stdc++.h>
using namespace std;

class TreeNode{
	public:
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int data){
		this->val = data;
		this->left = nullptr;
		this->right = nullptr;
	}
};

class Solution{
	public:
	TreeNode* createBinaryTree(vector<vector<int>>& des) {
    	unordered_map<int, TreeNode*>uM;
		unordered_set<int>c;
		
		for(int i = 0; i < des.size(); i++){
			c.insert(des[i][1]);
            
            uM.insert({des[i][1], new TreeNode(des[i][1])}); // for child
            
            uM.insert({des[i][0], new TreeNode(des[i][0])});  // for parent
		}

        TreeNode *root;
        for(int i = 0; i < des.size(); i++){
            
            if(des[i][2] == 1)   uM[des[i][0]] -> left = uM[des[i][1]];
            
            else   uM[des[i][0]] -> right = uM[des[i][1]];
            
            if (c.find(des[i][0]) == c.end()) root = uM[des[i][0]];
        }

        return root;	   
    }
};
