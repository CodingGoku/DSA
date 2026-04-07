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

// my method
bool preorder(TreeNode* p, TreeNode* q) {
        // when both are same, at the end both point to null
        if(p == NULL && q == NULL) return true;
        // below line is must as NULL->val, NULL->left, NULL->right will lead to runtime error
        // In C++, trying to access a member of a null pointer results in undefined behavior, 
        // and in this case, it leads to a runtime error.
        if(p == NULL || q == NULL) return false;

        if(p->val != q->val) return false;
        bool left = preorder(p->left, q->left);
        bool right = preorder(p->right, q->right);
        // we need to check if any subtree is giving false then return it
        return left && right;
    }

// preorder traversal
// T : O(N)
// S : O(N)
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == NULL || q == NULL)
        return p == q; // if one doesn't match return false else true i.e. NULL == (location the pointer points) or NULL == NULL

    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main()
{
    struct TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->right->left = new TreeNode(4);
    p->right->right = new TreeNode(5);

    struct TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);
    q->right->left = new TreeNode(4);
    q->right->right = new TreeNode(5);

    cout<<isSameTree(p, q);

    return 0;
}