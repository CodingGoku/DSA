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

// T : O(N)
// S : O(N)

// we are following Level Order Traversal
// and we'll use the last updated vertical value
vector<int> bottomView(TreeNode* root) {
    map<int, int> map; // vertical, val

    queue<pair<TreeNode*, int>> q; // node, vertical
    q.push({root, 0});
    while(!q.empty()) {
        auto p = q.front();
        q.pop();

        TreeNode* node = p.first;
        int vertical = p.second;

        // we'll let the map update it at each level
        // so that we get the bottom ones
        map[vertical] = node->val;

        if(node->left) q.push({node->left, vertical-1});
        if(node->right) q.push({node->right, vertical+1});
    }

    vector<int> result;
    for(auto& i : map) result.push_back(i.second); // insert value

    return result;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9);

    vector<int> result = bottomView(root);

    for(int i : result) cout<<i<<" ";
    return 0;
}