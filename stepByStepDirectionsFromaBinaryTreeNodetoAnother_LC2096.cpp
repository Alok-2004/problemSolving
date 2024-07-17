//2096. Step-By-Step Directions From a Binary Tree Node to Another
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

class Solution {
public:
    TreeNode* findLCA(TreeNode* root, int p, int q) {
        if (!root || root->val == p || root->val == q) return root;

        TreeNode* left = findLCA(root->left, p, q);
        TreeNode* right = findLCA(root->right, p, q);

        if (left && right) return root;
        return left ? left : right;
    }

    bool findPath(TreeNode* root, int val, string &path) {
        if (!root) return false;
        if (root->val == val) return true;

        path.push_back('L');
        if (findPath(root->left, val, path)) return true;
        path.pop_back();

        path.push_back('R');
        if (findPath(root->right, val, path)) return true;
        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int sV, int lV) {
        if (root == nullptr) return "";

        TreeNode* LCA = findLCA(root, sV, lV);

        string pathToStart, pathToEnd;

        findPath(LCA, sV, pathToStart);
        findPath(LCA, lV, pathToEnd);

        for (char &ch : pathToStart) ch = 'U';

        return pathToStart + pathToEnd;
    }
};


int main(){
	
}
