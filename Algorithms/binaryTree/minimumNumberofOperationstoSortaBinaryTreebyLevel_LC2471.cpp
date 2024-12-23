/*
2471. Minimum Number of Operations to Sort a Binary Tree by Level

You are given the root of a binary tree with unique values.

In one operation, you can choose any two nodes at the same level and swap their values.

Return the minimum number of operations needed to make the values at each level sorted in a strictly increasing order.

The level of a node is the number of edges along the path between it and the root node
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int len = q.size();
            vector<int> level;

            for (int i = 0; i < len; ++i) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            ans += countSwaps(level);
        }

        return ans;
    }

private:
    int countSwaps(vector<int>& level) {
        int n = level.size();
        vector<int> sortedLevel(level);
        sort(sortedLevel.begin(), sortedLevel.end());
        unordered_map<int, int> indexMap;

        for (int i = 0; i < n; ++i) {
            indexMap[level[i]] = i;
        }

        int swaps = 0;
        for (int i = 0; i < n; ++i) {
            if (level[i] != sortedLevel[i]) {
                int correctIndex = indexMap[sortedLevel[i]];

                indexMap[level[i]] = correctIndex;
                indexMap[level[correctIndex]] = i;

                swap(level[i], level[correctIndex]);
                swaps++;
            }
        }

        return swaps;
    }
};

int main(){
	
}
