#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data)
    {
        int val = data;
        left = right = NULL;
    }
};

// T : O(N)
// S : O(2N) ... 2 stacks
vector<int> postorderTraversal(TreeNode* root)
{
    vector<int> postorder;
    if(root == NULL) return postorder;
    stack<TreeNode*> st1,st2;
    st1.push(root);
    while(!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root);

        if(root->left != NULL) st1.push(root->left);
        if(root->right != NULL) st1.push(root->right);
    }
    // get the answer from st2
    while(!st2.empty())
    {
        postorder.push_back(st2.top()->val);
        st2.pop();
    }
    return postorder;
}


int main()
{
    return 0;
}