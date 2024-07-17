class Solution {
public:
    Node* createTree(const vector<int>& p) {
        if (p.empty()) return nullptr;
        
        int n = p.size();
        vector<Node*> nodes(n, nullptr);
        
        for (int i = 0; i < n; ++i) {
            nodes[i] = new Node(i);
        }
        
        for (int i = 0; i < n; ++i) {
            int parentIndex = p[i];
            if (parentIndex == -1) continue;
            
            if (nodes[parentIndex]->left == nullptr) {
                nodes[parentIndex]->left = nodes[i];
            } else if (nodes[parentIndex]->right == nullptr) {
                nodes[parentIndex]->right = nodes[i];
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (p[i] == -1) return nodes[i];
        }
        
        return nullptr;
    }
};
