/*
987. Vertical Order Traversal of a Binary Tree
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.
*/

#include<bits/stdc++.h
using namespace std;

class Solution {
public:
    void solve(map<int, vector<pair<int, int>>>& mp, int flag, TreeNode* root, unordered_map<int, pair<int, int>>& idx, int level) {
        if (root == nullptr) return;
        
        mp[flag].push_back({level, root->val});
        
        solve(mp, flag - 1, root->left, idx, level + 1);
        solve(mp, flag + 1, root->right, idx, level + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> mp;
        
        solve(mp, 0, root, idx, 0);
        
        vector<vector<int>> result;

        for (auto& pair : mp) {
            sort(pair.second.begin(), pair.second.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                if (a.first == b.first) {
                    return a.second < b.second; 
                }
                return a.first < b.first;
            });
            
            vector<int> columnValues;
            for (auto& p : pair.second) {
                columnValues.push_back(p.second);
            }
            result.push_back(columnValues);
        }

        return result;
    }
};

int main(){
	
}
