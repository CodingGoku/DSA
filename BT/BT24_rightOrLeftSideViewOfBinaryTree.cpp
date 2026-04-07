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
// S : O(N) ... as in level order the stack is storing N/2 in last level

// we are following Level Order Traversal
vector<int> leftSideView(TreeNode* root) {
    vector<int> result;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        for(int i=0; i<size; i++) {
            TreeNode* node = q.front();
            q.pop();

            if(i == 0) result.push_back(node->val); // at each level, only first element is inserted

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }

    return result;
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        for(int i=0; i<size; i++) {
            TreeNode* node = q.front();
            q.pop();

            if(i == size-1) result.push_back(node->val); // at each level, only last element is inserted

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }

    return result;
}

// Recursive
// T : O(N)
// S : O(H) in case of Skew Binary Tree, but it is very rare
void rightSideViewRec(TreeNode* root, int level, vector<int>& res) {
    if(!root) return;

    // to ensure that at each level we insert only once
    if(level == res.size()) res.push_back(root->val);

    rightSideViewRec(root->right, level+1, res);
    rightSideViewRec(root->left, level+1, res);
}

void leftSideViewRec(TreeNode* root, int level, vector<int>& res) {
    if(!root) return;

    // to ensure that at each level we insert only once
    if(level == res.size()) res.push_back(root->val);

    leftSideViewRec(root->left, level+1, res);
    leftSideViewRec(root->right, level+1, res);
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->left->right->left = new TreeNode(6);

    vector<int> result = leftSideView(root);
    cout<<"\nleft side view : ";
    for(int i : result) cout<<i<<" ";

    result = rightSideView(root);
    cout<<"\nright side view : ";
    for(int i : result) cout<<i<<" ";

    cout<<"\n\nRECURSIVE:\n";
    cout<<"left side view : ";
    vector<int> r;
    leftSideViewRec(root, 0, r);
    for(int i : r) cout<<i<<" ";
    cout<<"\nright side view : ";
    vector<int> res;
    rightSideViewRec(root, 0, res);
    for(int i : res) cout<<i<<" ";

    return 0;
}