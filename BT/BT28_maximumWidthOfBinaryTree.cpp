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

// T : O(N) ... same as level order
// S : O(N) ... for using queue
int maximumWidthOfBinaryTree(TreeNode* root) {
    if(root == NULL) return 0;

    int ans = 0;
    queue<pair<TreeNode*, int>> q; // node, index
    q.push({root, 0});

    // level order traversal
    while(!q.empty()) {
        int size = q.size();
        int mmin = q.front().second; // to set first index to 0
        int first, last;
        for(int i=0; i<size; i++) {
            int curr_id = q.front().second - mmin;
            TreeNode* node = q.front().first;
            q.pop();

            if(i==0) first = curr_id; // if one node at current level then first and last are same
            if(i==size-1) last = curr_id; // so don't use `else`

            if(node->left) q.push({node->left, curr_id*2+1});
            if(node->right) q.push({node->right, curr_id*2+2});
        }
        ans = max(ans, last-first+1);
    }
    return ans;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(8);
    root->right->right = new TreeNode(4);

    cout<<"Max Width of BT : "<<maximumWidthOfBinaryTree(root);
    return 0;
}