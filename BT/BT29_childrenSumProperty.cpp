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
// S : O(1)
void changeTree(TreeNode* root) {
    if(root == NULL) return;
    int child = 0;
    if(root->left) child += root->left->data;
    if(root->right) child += root->right->data;

    if(child >= root->data) root->data = child;
    else {
        root->left->data = root->data;
        root->right->data = root->data;
    }

    changeTree(root->left); // left traversal
    changeTree(root->right); // right traversal

    // when returning, root should be sum of left and right
    int tot=0;
    if(root->left) tot += root->left->data;
    if(root->right) tot += root->right->data;
    if(root->left || root->right) root->data = tot; // if root is not leaf node ... root data is sum of its child
}

int main()
{
    return 0;
}