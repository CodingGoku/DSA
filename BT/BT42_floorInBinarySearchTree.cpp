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

int floor(TreeNode* root, int key) {
    int floor = -1;

    while(root != NULL) {
        if(root->data == key) {
            floor = root->data;
            return floor;
        }

        if(root->data > key) {
            root = root->left;
        }

        else {
            floor = root->data;
            root = root->right;
        }
    }

    return  floor;
}

int main()
{
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(5);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);
    root->left->right->left = new TreeNode(6);
    root->right->right->left = new TreeNode(13);

    int f = floor(root, 9); // floor is value just <= key
    cout<<f;

    return 0;
}