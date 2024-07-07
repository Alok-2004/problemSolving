// Vertical width of a tree

// TC is O(n) and SC is O(max(h, n)) h is for recursive stack
/*
class Solution {
  public:
    
    int helper(Node* root, int flag, unordered_map<int, int>&m){
        if(root == nullptr) return 0;
        m[flag]++;
        helper(root->left, flag - 1, m);
        helper(root->right, flag + 1, m);
        return m.size();
    }
    
    int verticalWidth(Node* root) {
        if(root == nullptr) return 0;
        unordered_map<int, int>m;
        int res = helper(root, 0, m);
        return res;
    }
};
*/

// More optimized method which is not using unordered_map
class Solution {
  public:
    
    int helper(Node* root, int flag, int &minFlag, int &maxFlag){
        if(root == nullptr) return 0;
        if(flag > 0) maxFlag = max(maxFlag, flag);
        if(flag < 0) minFlag = min(minFlag, flag);
        helper(root->left, flag - 1, minFlag, maxFlag);
        helper(root->right, flag + 1, minFlag, maxFlag);
        return maxFlag - minFlag + 1;
    }
    
    int verticalWidth(Node* root) {
        if(root == nullptr) return 0;
        int res = helper(root, 0, m);
        return res;
    }
};


