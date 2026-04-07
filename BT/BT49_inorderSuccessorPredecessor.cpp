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
// S : O(1)
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* successor = NULL; // if no successor returns NULL

    while(root != NULL) {
        if(root->data <= p->data) root = root->right;
        else { // root->data > p->data
            successor = root;
            root = root->left; // to get value just greater than p->data
        }
    }

    return successor;
}

TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p) {
    TreeNode* predecessor = NULL; // if no predecessor returns NULL

    while(root != NULL) {
        if(root->data >= p->data) root = root->left;
        else { // root->data > p->data
            predecessor = root;
            root = root->right; // to get value just smaller than p->data
        }
    }

    return predecessor;
}

int main()
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    root->left->left->left = new TreeNode(1);
    root->right->right->left = new TreeNode(8);
    root->right->right->right = new TreeNode(10);

    TreeNode* eight = root->right->right->left;
    TreeNode* s = inorderSuccessor(root, eight);
    cout<<"successor: "<<s->data<<"\n";

    TreeNode* p = inorderPredecessor(root, eight);
    cout<<"predecessor: "<<p->data;
    return 0;
}