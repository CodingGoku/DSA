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

// RECURSIVE
// T : O(N)
// S : O(N)
void flatten(TreeNode* &node, TreeNode* &prev) {

    if(node == NULL) return;

    flatten(node->right, prev);
    flatten(node->left, prev);

    node->right = prev;
    node->left = NULL;
    prev = node;
}

int main()
{
    TreeNode* prev = NULL;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    root->right->right->left = new TreeNode(7);

    flatten(root, prev);

    while(root) {
        cout<<root->data<<" ";
        root = root->right;
    }
    return 0;
}