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

bool isLeaf(TreeNode* root) {
    return !root -> left && !root -> right; // root's left and right should be null for it to be a leaf
}

void leftBoundary(TreeNode* root, vector<int>& ans) {
    TreeNode* node = root->left; // moves to left side
    while(node) {
        if(!isLeaf(node)) ans.push_back(node->val);
        if(node->left) node = node->left;
        else node = node->right;
    }
}


void leafNodes(TreeNode* root, vector<int>& ans) {
    if(isLeaf(root)) {
        ans.push_back(root->val);
        return;
    }

    // can be a possibility when either left or right does not exits but it is not the root
    if(root->left) leafNodes(root->left, ans); // if left exists then only go left
    if(root->right) leafNodes(root->right, ans); // if right exists then only go right
}

void rightBoundary(TreeNode* root, vector<int>& ans) {
    TreeNode* node = root->right; // moves to right side

    vector<int> temp; // to store right boundary as we need to reverse it later and then add it
    while(node) {
        if(!isLeaf(node)) temp.push_back(node->val);
        if(node->right) node = node->right;
        else node = node->left;
    }

    // inserting right boundary in reverse order
    for(int i=temp.size()-1; i>=0; i--) {
        ans.push_back(temp[i]);
    }
}

// T : O(N) ... O(Height) for left + O(Height) for right + O(N) for nodes as they required full traversal
// S : O(N) ... recursive
vector<int> boundary(TreeNode* root) {

    vector<int> ans;

    if(!root) return ans; // if root is null
    if(!isLeaf(root)) ans.push_back(root->val); // added the root

    // left boundary excluding leaf nodes
    leftBoundary(root, ans);

    // leaf nodes
    leafNodes(root, ans);

    // right boundary excluding leaf nodes and root node
    rightBoundary(root, ans);

    return ans;
}

int main()
{
    struct TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(3);
    root->right->right = new TreeNode(8);
    root->left->left->right = new TreeNode(4);
    root->right->right->left = new TreeNode(9);
    root->left->left->right->left = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);
    root->right->right->left->left = new TreeNode(10);
    root->right->right->left->right = new TreeNode(11);

    vector<int> ans = boundary(root);
    for(auto& i : ans) cout<<i<<" ";
    return 0;
}