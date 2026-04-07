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

// T : O(N) ... have to visit each node
// S : O(N) ... in worst case if it is a skew tree
int maxDepth(TreeNode* root)
{
    if(root == NULL) return 0;

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    return 1 + max(lh, rh);
}

int main()
{

    return 0;
}