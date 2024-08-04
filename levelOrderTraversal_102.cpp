class Solution {
public:

    int height(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    void traversal(TreeNode* root, int check, int level,  vector<int> &v){
        if(root == NULL) return;
        if(check == level){
            v.push_back(root->val);
            return;
        }
        traversal(root->left, check + 1, level, v);
        traversal(root->right, check + 1, level, v);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        int levels = height(root);
        vector<vector<int>>ans(levels);
        for(int i = 0; i<levels; i++){
            traversal(root, 1, i+1, ans[i]);
        }
        return ans;
    }
};
