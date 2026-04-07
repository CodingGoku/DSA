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
// S : O(N) ... auxiliary stack space in case of skew tree
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL || root == p || root == q) return root;

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if(left == NULL) return right; // right could also be NULL
    else if(right == NULL) return left; // left could also be NULL
    else return root; // when both left and right are not NULL, we are at the lowest common ancestor
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);

    // lca(4,7) = 2
    cout<<lowestCommonAncestor(root, root->left->left, root->left->right->right)->val;

    return 0;
}