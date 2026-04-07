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

// T : O(Log(N)) ... similar to height of tree as we are traversing the height of tree
// S : O(1)
TreeNode* search(TreeNode* root, int val) {
    while(root != NULL && root->data != val) {
        root = val < root->data ? root->left : root->right;
    }
    return root; // root returns the node with the given value if found else it returns NULL
}

int main()
{
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(5);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);
    root->left->right->left = new TreeNode(6);
    root->right->right->left = new TreeNode(13);

    TreeNode* found = search(root, 10);
    cout<<found->data;
    return 0;
}