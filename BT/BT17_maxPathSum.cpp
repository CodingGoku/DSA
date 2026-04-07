#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data)
    {
        val = data;
        left = right = NULL;
    }
};


// T : O(N) ... visiting each node once
// S : O(N) ... O(H), where H is the height of the binary tree.
// In the worst case, if the tree is skewed (e.g., a linked list), the height becomes N, and the space complexity is O(N)
int maxPathSum(TreeNode* root, int& maxi) {
    if(root == NULL) return 0;

    // calculates left branch maxPathSum
    int leftSum = max(0, maxPathSum(root->left, maxi)); // if leftSum is -ve we return 0 as we want to maximize
    // calculates right branch maxPathSum
    int rightSum = max(0, maxPathSum(root->right, maxi)); // if rightSum is -ve we return 0 as we want to maximize

    // maxi is the current maxPathSum
    maxi = max(maxi, leftSum+rightSum+root->val);

    // return  the maxPathSum of one side
    return root->val + max(leftSum, rightSum);
}

int main()
{
    struct TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    int maxi = INT_MIN;
    maxPathSum(root, maxi);
    // remember that maxi gives the maxPathSum and not the function
    cout<<maxi;
    return 0;
}