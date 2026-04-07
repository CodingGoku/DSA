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

void printBT(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        vector<int> level;
        
        for(int i=0; i<size; i++) {
            TreeNode* currNode = q.front();
            q.pop();

            level.push_back(currNode->data);
            if(currNode->left) q.push(currNode->left);
            if(currNode->right) q.push(currNode->right);
        }
        ans.push_back(level);
    }

    for(auto i : ans) {
        for(auto j : i) cout<<j<<" ";
        cout<<"\n";
    }
}

TreeNode* findLastRight(TreeNode* root) {
    if(root->right == NULL) return root;

    return findLastRight(root->right);
}

// to delete the root node
TreeNode* helper(TreeNode* root) {
    if(root->left == NULL) return root->right;
    if(root->right == NULL) return root->left;

    TreeNode* rightChild = root->right;
    TreeNode* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}

TreeNode* remove(TreeNode* root, int key) {
    if(root == NULL) return root;

    if(key == root->data) return helper(root);

    TreeNode* dummy = root;
    while(root != NULL) {
        if(root->data > key) {
            if(root->left != NULL && root->left->data == key) { // NULL condition is important as you cannot access the data otherwise
                root->left = helper(root->left);
                break;
            }
            else root = root->left;
        }
        else {
            if(root->right != NULL && root->right->data == key) {
                root->right = helper(root->right);
                break;
            }
            else root = root->right;
        }
    }

    return dummy;
}


int main()
{
    TreeNode* root = new TreeNode(9);
    root->left = new TreeNode(8);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(5);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(13);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(7);
    root->right->left->right = new TreeNode(11);
    root->left->left->left->left = new TreeNode(2);
    root->left->left->left->right = new TreeNode(4);
    root->left->left->right->left = new TreeNode(6);
    root->left->left->right->right = new TreeNode(8);
    root->left->left->left->left->left = new TreeNode(1);

    root = remove(root, 5);
    printBT(root);
    return 0;
}