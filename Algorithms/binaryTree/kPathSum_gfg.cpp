/*
K Sum Paths
Given a binary tree and an integer k, determine the number of downward-only paths where the sum of the node values in the path equals k.
A path can start and end at any node within the tree but must always move downward (from parent to child).
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    void solve(Node *root, int k, int sum, unordered_map<int, int> &prefix, int &res)
    {
        if (!root)
            return;

        sum += root->data;
        if (sum == k)
            res++;

        res += prefix[sum - k];
        prefix[sum]++;

        solve(root->left, k, sum, prefix, res);
        solve(root->right, k, sum, prefix, res);

        prefix[sum]--;
    }

    int sumK(Node *root, int k)
    {
        unordered_map<int, int> prefix;
        int res = 0;
        solve(root, k, 0, prefix, res);
        return res;
    }
};

int main()
{
}