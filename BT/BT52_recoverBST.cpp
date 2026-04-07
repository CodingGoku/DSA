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
// S : O(N) ... recursive stack space
void inorder(TreeNode* root, TreeNode* &prev, TreeNode* &first, TreeNode* &middle, TreeNode* &last) {
    if(root == NULL) return;

    inorder(root->left, prev, first, middle, last);

    if(root->data < prev->data) { // if we reach a violation
        // first violation
        if(first == NULL) {
            first = prev;
            middle = root;
        }
        // second violation
        else last = root;
    }

    prev = root;
    inorder(root->right, prev, first, middle, last);
}

void swap(TreeNode* &first, TreeNode* &second) {
    int temp = first->data;
    first->data = second->data;
    second->data = temp;
}

TreeNode* recoverBST(TreeNode* root) {
    TreeNode* first = NULL;
    TreeNode* middle = NULL;
    TreeNode* last = NULL;
    TreeNode* prev = new TreeNode(INT_MIN); // there will be no node less than this ... so first node cannot be violated
                                            // for violation: root->data < prev->data ... prev is set INT_MIN

    inorder(root, prev, first, middle, last);
    if(first && last) swap(first->data, last->data); // if not adjacent nodes
    else if(first && middle) swap(first->data, middle->data); // if adjacent nodes
}

int main()
{
    
    return 0;
}