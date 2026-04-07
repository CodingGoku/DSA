#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

// T : O(N)
// S : O(N) or the height of the tree for stack size
vector<int> inorderTraversal(TreeNode* root)
{
    TreeNode* node = root;
    stack<TreeNode*> st;
    vector<int> inorder;

    while(true)
    {
        if(node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if(st.empty()) break;
            node = st.top();
            st.pop();
            inorder.push_back(node->val);
            node = node->right;
        }
    }
    
    return inorder;
}

int main()
{
    return 0;
}