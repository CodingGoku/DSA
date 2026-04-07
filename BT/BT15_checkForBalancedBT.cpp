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

// Previous Question code
int findHeight(TreeNode* root)
{
    if(root == NULL) return 0;

    int lh = findHeight(root->left);
    int rh = findHeight(root->right);

    return 1 + max(lh, rh);
}

// Brute Force
// T : O(N^2) ... N for traversal and N for findHeight()
bool check(TreeNode* node)
{
    if(node == NULL) return true;

    int lh = findHeight(node->left);
    int rh = findHeight(node->right);

    if(abs(rh - lh) > 1) return false;

    // check for sub-branches recursively
    bool left = check(node->left);
    bool right = check(node->right);
    if(!left || !right) return false;
    return true;
}

// Better Approach
// T : O(N)
int findHeight(TreeNode* root)
{
    if(root == NULL) return 0;

    int lh = findHeight(root->left);
    // Modification 1
    if(lh == -1) return -1; // returning -1 means not balanced

    int rh = findHeight(root->right);
    // Modification 2
    if(rh == -1) return -1;

    // Modification 3
    // for the below code modification as it will return to either lh or rh
    if(abs(lh-rh) > 1) return -1;

    return 1 + max(lh, rh);
}

int main()
{
    return 0;
}