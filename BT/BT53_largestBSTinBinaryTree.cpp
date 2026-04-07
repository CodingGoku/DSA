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

class NodeValue {
    public:
    int minNode, maxNode, maxSize;

    NodeValue(int minNode, int maxNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

// T: O(N)
// S: O(N) ... recursive stack space, height of the tree
NodeValue largestBSTSubtreeHelper(TreeNode* root) {
    // An empty tree is a BST of size 0
    if(root == NULL) return NodeValue(INT_MAX, INT_MIN, 0);

    // get values from left and right subtree of current node
    auto left = largestBSTSubtreeHelper(root->left);
    auto right = largestBSTSubtreeHelper(root->right);

    // current node should be greater than max in left AND smaller than min in right
    if(left.maxNode < root->data && root->data < right.minNode) {
        // it is a BST ... we are taking min and max of left with root and right with root, as that node can be a NULL
        // and NULL's min is INT_MAX, NULL's max is INT_MIN
        return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), left.maxSize + right.maxSize + 1);
    }

    // otherwise return [-inf, inf] so that parent can't be valid BST
    return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}

int largestBSTSubtree(TreeNode* root) {
    return largestBSTSubtreeHelper(root).maxSize;
}

int main()
{
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(15);
    root->right = new TreeNode(40);
    root->left->left = new TreeNode(14);
    root->left->right = new TreeNode(18);
    root->right->left = new TreeNode(30);
    root->right->right = new TreeNode(60);
    root->left->left->right = new TreeNode(17);
    root->left->right->left = new TreeNode(16);
    root->left->right->right = new TreeNode(19);
    root->right->right->left = new TreeNode(50);

    cout<<largestBSTSubtree(root);

    return 0;
}