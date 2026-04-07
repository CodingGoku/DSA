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


void printTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        
        for(int i=0; i<size; i++) {
            TreeNode* currNode = q.front();
            q.pop();

            cout<<currNode->data<<" ";

            if(currNode->left) q.push(currNode->left);
            if(currNode->right) q.push(currNode->right);
        }
        cout<<"\n";
    }
}

// T : O(N)
// S : O(N) ... recursive stack space in case of skew tree
TreeNode* build(vector<int>& preorder, int& i, int bound) {
    if(i == preorder.size() || preorder[i] > bound) return NULL;

    TreeNode* root = new TreeNode(preorder[i++]);
    root->left = build(preorder, i, root->data);
    root->right = build(preorder, i, bound);

    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i = 0;
    return build(preorder, i, INT_MAX);
}

int main()
{
    vector<int> preorder = {8,5,1,7,10,12};
    TreeNode* root = bstFromPreorder(preorder);
    printTree(root);
    return 0;
}