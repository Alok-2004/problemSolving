/*
2641. Cousins in Binary Tree II
Given the root of a binary tree, replace the value of each node in the tree with the 
sum of all its cousins' values.

Two nodes of a binary tree are cousins if they have the same depth with different 
parents.

Return the root of the modified tree.

Note that the depth of a node is the number of edges in the path from the root node 
to it.
*/
#include<bits/stdc++.h>
using namespace std;

static const int _ = [] {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class TreeNode{
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	
	TreeNode(int _val){
		val = _val;
		left == nullptr;
		right = nullptr;
	}
};


class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root == NULL) {
            return root;
        }        

        queue<TreeNode*> que;
        que.push(root);
        int levelSum = root->val;

        while(!que.empty()) {
            int n = que.size();
            int nextLevelSum = 0;

            while(n--) {
                TreeNode* curr = que.front();
                que.pop();

                curr->val = levelSum - curr->val;

                int siblingSum = (curr->left != NULL ? curr->left->val : 0);
                siblingSum += (curr->right != NULL ? curr->right->val : 0);

                if(curr->left) {
                    nextLevelSum += curr->left->val;
                    curr->left->val = siblingSum;
                    que.push(curr->left);
                }


                if(curr->right) {
                    nextLevelSum += curr->right->val;
                    curr->right->val = siblingSum;
                    que.push(curr->right);
                }
            }

            levelSum = nextLevelSum;
        }

        return root;
    }
};

//TLE
/*

class Solution {
public:

    int levels(TreeNode* root) {
        if (root == nullptr) return 0;
        else return 1 + max(levels(root->right), levels(root->left));
    }

    void dfs(TreeNode* root, int level, vector<vector<pair<TreeNode*, TreeNode*>>>& score, unordered_map<TreeNode*, int>& mp) {
        if (root == nullptr) return;

        mp[root] = root->val;

        if (root->right) score[level+1].push_back({root->right, root});
        if (root->left) score[level+1].push_back({root->left, root});

        dfs(root->left, level + 1, score, mp);
        dfs(root->right, level + 1, score, mp);
    }

    void finalDFS(TreeNode* root, int level, vector<vector<pair<TreeNode*, TreeNode*>>>& score, unordered_map<TreeNode*, int>& mp) {
        if (root == nullptr) return;

        int sum = 0;
        TreeNode* parent = nullptr;
        
        for (auto& p : score[level]) {
            if (p.first == root) {
                parent = p.second;
                break;
            }
        }

        for (auto& p : score[level]) {
            if (p.second != parent && p.second != nullptr) {
                sum += mp[p.first];
            }
        }

        root->val = sum;

        finalDFS(root->left, level + 1, score, mp);
        finalDFS(root->right, level + 1, score, mp);
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<vector<pair<TreeNode*, TreeNode*>>> score;  // child and parent
        unordered_map<TreeNode*, int> mp; // Node and value

        int height = levels(root);
        score.resize(height); // Ensure score is resized based on the tree height

        score[0].push_back({root, nullptr});
        dfs(root, 0, score, mp);
        finalDFS(root, 0, score, mp);

        return root;
    }
};
*/


int main(){
	
}
