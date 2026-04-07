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

// T : O(N)
// S : O(1)
vector<int> getInorder(TreeNode* root) {
    vector<int> inorder;
    TreeNode* cur = root;

    while(cur != NULL) {
        if(cur->left == NULL) {
            inorder.push_back(cur->data);
            cur = cur->right;
        }
        else {
            TreeNode* prev = cur->left;
            while(prev->right && prev->right != cur) {
                prev = prev->right;
            }

            if(prev->right == NULL) {
                prev->right = cur; // add thread
                cur = cur->left;
            }
            else { // when prev->right == cur
                prev->right = NULL; // remove thread
                inorder.push_back(cur->data);
                cur = cur->right;
            }
        }
    }
    return inorder;
}

vector<int> getPreorder(TreeNode* root) {
    vector<int> inorder;
    TreeNode* cur = root;

    while(cur != NULL) {
        if(cur->left == NULL) {
            inorder.push_back(cur->data);
            cur = cur->right;
        }
        else {
            TreeNode* prev = cur->left;
            while(prev->right && prev->right != cur) {
                prev = prev->right;
            }

            if(prev->right == NULL) {
                prev->right = cur; // add thread
                inorder.push_back(cur->data); //only change for preorder
                cur = cur->left;
            }
            else { // when prev->right == cur
                prev->right = NULL; // remove thread
                cur = cur->right;
            }
        }
    }
    return inorder;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);

    vector<int> inorder = getInorder(root);
    for(int i : inorder) cout<<i<<" ";
    return 0;
}