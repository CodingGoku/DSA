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

int height(TreeNode* root) {
    if(root == NULL) return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return 1 + max(lh, rh);
}

// T : O(Log(N)^2) ... Log(N) for function and Log(N) for calculating height each time
// S : O(Log(N)) ... recursive stack space
int countNodes(TreeNode* root) {
    if(root == NULL) return 0;

    int lh = height(root->left);
    int rh = height(root->right);
    if(lh == rh) return pow(2,height(root))-1; // no. of nodes = 2^height - 1

    return 1+countNodes(root->left)+countNodes(root->right);
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(11);
    
    cout<<"Nodes : "<<countNodes(root);
    return 0;
}