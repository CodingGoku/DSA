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

// T : O(N) ... same as level order
// S : O(N) ... same as level order
vector<vector<int>> zigzag(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == NULL) return ans;

    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;

    while(!q.empty()) {
        int size = q.size();
        vector<int> row(size);

        // for each element in a row
        for(int i=0; i<size; i++) {
            TreeNode* node = q.front();
            q.pop();

            // find position to fit node's value
            int index = (leftToRight) ? i : size-i-1;
            // now insert it at that position
            row[index] = node->val;

            // inserting next level in queue
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        // switch direction
        leftToRight = !leftToRight;
        // push row in ans
        ans.push_back(row);
    }
    return ans;
}

int main()
{
    struct TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    vector<vector<int>> ans = zigzag(root);
    for(auto& i : ans) {
        for(auto& j : i) {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    return 0;
}