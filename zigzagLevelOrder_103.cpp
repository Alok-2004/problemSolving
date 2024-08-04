class Solution {
public:
  int levels(TreeNode *root){
    if(root == NULL) return 0;
    return 1 + max(levels(root->left), levels(root->right));
  }
  
  void oddHelper(TreeNode* root, int check, int level, vector<int> &v){
  //here level will be used for checkng whether for pushing or not
    if(root == NULL) return;
    if(check == level){
        v.push_back(root->val);
        return;
    }
    oddHelper(root->left, check+1, level, v);
    oddHelper(root->right, check+1, level, v);
  }

  void evenHelper(TreeNode* root, int check, int level, vector<int> &v){
    if(root == NULL) return;
    if(check == level){
        v.push_back(root->val);
        return;
    }
    evenHelper(root->right, check+1, level, v);
    evenHelper(root->left, check+1, level, v);
  }

  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    int n = levels(root);
    vector<vector<int>> v(n);
    for(int i = 0; i<n; i++){
      if((i + 1) % 2 == 0)  evenHelper(root, 1, i+1, v[i]);
      else oddHelper(root, 1, i+1, v[i]);
    }
    return v;
  }
};
