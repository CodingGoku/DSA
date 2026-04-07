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
int ceil(TreeNode* root, int key) {
    int ceil = -1;
    while(root != NULL) {
        if(root->data == key) {
            ceil = root->data;
            return ceil;
        }

        if(root->data < key) {
            root = root->right;
        }

        else {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
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

    int c = ceil(root, 11); // ceil is value just >= key
    cout<<c;
    return 0;
}