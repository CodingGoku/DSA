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

// T : O(N)
// S : O(1)
TreeNode* insert(TreeNode* root, int val) {
    if(root == NULL) return new TreeNode(val);

    TreeNode* curr = root;
    while(curr != NULL) {
        if(curr->data < val) {
            if(curr->right) curr = curr->right;
            else {
                curr->right = new TreeNode(val);
                break;
            }
        }
        else {
            if(curr->left) curr = curr->left;
            else {
                curr->left = new TreeNode(val);
                break;
            }
        }
    }

    return root;
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

    root = insert(root, 9);

    printBT(root);

    return 0;
}