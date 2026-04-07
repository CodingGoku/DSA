#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data)
    {
        int val = data;
        left = right = NULL;
    }
};

// same code as maxDepth just added diameter
// T : O(N)
// S : O(N)
int height(TreeNode* node, int& diameter)
{
    if(!node) return 0;

    int lh = height(node->left, diameter);
    int rh = height(node->right, diameter);
    diameter = max(diameter, lh+rh+1);
    return 1 + max(lh, rh);
}

int diameterOfBinaryTree(TreeNode* root)
{
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

int main()
{
    return 0;
}