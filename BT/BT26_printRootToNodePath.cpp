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

// T : O(N) ... inorder traversal
// S : O(H) ... recursive stack space 
bool getPath(TreeNode* root, vector<int>& arr, int x) {
    if(!root) return false;

    arr.push_back(root->val);

    // if found return true
    if(root->val == x) return true;

    // if found at either left or right return true
    if(getPath(root->left, arr, x) || getPath(root->right, arr, x)) return true;

    // or if not found
    arr.pop_back();
    return false;
}

int main()
{
    vector<int> arr;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);

    getPath(root, arr, 7);
    for(int i : arr) cout<<i<<" ";
    return 0;
}