//This will not work because the the max/min heap method only work for complete binary tree and here tree can be skewed also
/*
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& td) {
        vector<TreeNode*> res;
        if (root == nullptr) return res;

        // First, make an array and push all the nodes into it
        vector<TreeNode*> curr;
        unordered_set<int> s(td.begin(), td.end());

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            curr.push_back(temp);
            if (temp->left != nullptr) q.push(temp->left);
            if (temp->right != nullptr) q.push(temp->right);
        }

        // Now check for nodes to delete using normal traversal
        // parent = (i - 1) / 2 for 0-indexed array
        // child = 2 * i + 1 (left), 2 * i + 2 (right)

        for (int i = 0; i < curr.size(); ++i) {
            TreeNode* node = curr[i];
            if (s.find(node->val) != s.end()) {
                if (node->left && s.find(node->left->val) == s.end()) {
                    res.push_back(node->left);
                }
                if (node->right && s.find(node->right->val) == s.end()) {
                    res.push_back(node->right);
                }
                if (i > 0) {
                    TreeNode* parent = curr[(i - 1) / 2];
                    if (parent->left == node) parent->left = nullptr;
                    if (parent->right == node) parent->right = nullptr;
                }
            } else {
                if (i == 0) res.push_back(node);
            }
        }

        return res;
    }
};
*/

class Solution {
public:

    void helper(TreeNode* &root, vector<TreeNode*> &res, unordered_set<int> st){
        if(root == nullptr)  return;
        
        helper(root->left, res, st);
        helper(root->right, res, st);

        if(st.find(root->val) != st.end()){
            if(root->left) res.push_back(root->left);
            if(root->right) res.push_back(root->right);
            root = nullptr;
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& td) {
        vector<TreeNode*>res;
        if(root == nullptr)  return res;
 
        unordered_set<int>st(td.begin(), td.end());
        helper(root, res, st);
        if(root) res.push_back(root);
        return res;
    }
};
