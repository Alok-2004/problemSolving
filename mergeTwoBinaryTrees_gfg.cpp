//Merging two binary trees
// convert both of them two array and merge them
//then convert back them two bst

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    void inorder(Node *root, vector<int> &v1) {
        if (root == nullptr) return;
        inorder(root->left, v1);
        v1.push_back(root->data);
        inorder(root->right, v1);
    }

    void mergeVectors(vector<int> &v1, vector<int> &v2, vector<int> &merge) {
        int i = 0; // for v1
        int j = 0; // for v2

        while (i < v1.size() && j < v2.size()) {
            if (v1[i] <= v2[j]) {
                merge.push_back(v1[i]);
                i++;
            } else {
                merge.push_back(v2[j]);
                j++;
            }
        }

        while (i < v1.size()) {
            merge.push_back(v1[i]);
            i++;
        }

        while (j < v2.size()) {
            merge.push_back(v2[j]);
            j++;
        }
    }

    Node* create(vector<int> &merge, int lo, int hi) {
        if (lo > hi) return nullptr;

        int mid = lo + (hi - lo) / 2;
        Node *temp = new Node(merge[mid]);
        temp->left = create(merge, lo, mid - 1);
        temp->right = create(merge, mid + 1, hi);

        return temp;
    }

    Node* merge(Node *root1, Node *root2) {
        vector<int> v1, v2;
        inorder(root1, v1);
        inorder(root2, v2);

        vector<int> merge;
        mergeVectors(v1, v2, merge);

        Node* root = create(merge, 0, merge.size() - 1);
        return root;
    }
};

void printInorder(Node* node) {
    if (node == nullptr) return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

int main() {
    Node* root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(4);

    Node* root2 = new Node(5);
    root2->left = new Node(2);
    root2->right = new Node(6);

    Solution sol;
    Node* mergedRoot = sol.merge(root1, root2);

    cout << "Inorder traversal of merged BST: ";
    printInorder(mergedRoot);
    cout << endl;

    return 0;
}

