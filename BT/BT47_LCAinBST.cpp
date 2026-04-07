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

// T : O(H)
// S : O(H) ... recursive stack space
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL) return NULL;

    TreeNode* cur = root;
    // when both are on one side, move to that side
    if(cur->data > p->data && cur->data > q->data) return lowestCommonAncestor(root->left, p, q);
    if(cur->data < p->data && cur->data < q->data) return lowestCommonAncestor(root->right, p, q);

    return root; //when p is on one side and q is on the other side, we know that this is the LCA
}

int main()
{
    return 0;
}