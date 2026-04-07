#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        val = data;
        left = right = NULL;
    }
};

// T : O(N)
// S : O(N) for skew tree

// check for mirror images
bool isSymmetricHelp(TreeNode* left, TreeNode* right) {
    if(left == NULL || right == NULL) return left == right;

    if(left->val != right->val) return false;

    //left of one side should match with right of other side and vice-versa
    return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    return root==NULL || isSymmetricHelp(root->left, root->right);
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    cout<<isSymmetric(root);
    return 0;
}