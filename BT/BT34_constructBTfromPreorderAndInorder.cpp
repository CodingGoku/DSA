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
// S : O(N) ... for map
TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder,int inStart, int inEnd, unordered_map<int, int>& inMap) {
    if(preStart > preEnd || inStart > inEnd) return NULL;

    TreeNode* root = new TreeNode(preorder[preStart]);

    int inRoot = inMap[root->data]; //index of root in inorder
    int numLeft = inRoot-inStart;

    root->left = buildTree(preorder, preStart+1, preStart+numLeft, inorder, inStart, inRoot-1, inMap);
    root->right = buildTree(preorder, preStart+numLeft+1, preEnd, inorder, inRoot+1, inEnd, inMap);

    return root;
}

TreeNode* construct(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inMap;
    for(int i=0; i<inorder.size(); i++) inMap[inorder[i]] = i; // inorder -> index

    return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
}


int main()
{
    vector<int> inorder = {9,3,15,20,7};
    vector<int> preorder = {3,9,20,15,7};

    TreeNode* root = construct(preorder, inorder);
    printBT(root);
    return 0;
}