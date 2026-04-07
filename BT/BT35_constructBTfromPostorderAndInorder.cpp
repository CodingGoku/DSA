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


// T : O(N) x Log(N) ... if you are considering hashMap to take Log(N) otherwise O(1) for it
// S : O(N) ... map
TreeNode* buildTree(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inMap) {
    if(postStart > postEnd || inStart > inEnd) return NULL;

    TreeNode* root = new TreeNode(postorder[postEnd]);
    int inRoot = inMap[root->data]; //index of root in inorder
    int numLeft = inRoot-inStart;

    root->left = buildTree(postorder, postStart, postStart+numLeft-1, inorder, inStart, inRoot-1, inMap);
    root->right = buildTree(postorder, postStart+numLeft, postEnd-1, inorder, inRoot+1, inEnd, inMap);

    return root;
}

TreeNode* construct(vector<int>& postorder, vector<int>& inorder) {
    unordered_map<int, int> inMap;
    for(int i=0; i<inorder.size(); i++) inMap[inorder[i]] = i; // inorder -> index

    return buildTree(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, inMap);
}

int main()
{
    vector<int> inorder = {40,20,50,10,60,30};
    vector<int> postorder = {40,50,20,60,30,10};

    TreeNode* root = construct(postorder, inorder);
    printBT(root);
    return 0;
}