#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

// T : O(N)
// S : O(N)
vector<int> preorderTraversal(Node* root)
{
    vector<int> preorder;
    if(root == NULL) return preorder;

    stack<Node*> st;
    st.push(root);
    while(!st.empty())
    {
        root = st.top();
        st.pop();
        preorder.push_back(root->data);
        // PREORDER is NLR but we push right, then left as in stack top will have left
        if(root->right != NULL) st.push(root->right);
        if(root->left != NULL) st.push(root->left);
    }
    return preorder;
}

int main()
{
    return 0;
}