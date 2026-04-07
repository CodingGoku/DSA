#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int d) {
        data = d;
        left = right = NULL;
    }
};

// T : O(N)
// S : O(N)
bool isBST(TreeNode* root, long minVal, long maxVal) {
    if(root == NULL) return true;

    if(root->data >= maxVal || root->data <= minVal) return false;

    return isBST(root->left, minVal, root->data) && isBST(root->right, root->data, maxVal); 
}

int main()
{
    TreeNode* root = new TreeNode(13);
    root->left = new TreeNode(10);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(12);
    root->right->left = new TreeNode(14);
    root->right->right = new TreeNode(17);
    root->left->left->right = new TreeNode(9);
    root->right->right->left = new TreeNode(16);
    root->left->left->right->left = new TreeNode(8);

    cout<<isBST(root, INT_MIN, INT_MAX);
    return 0;
}