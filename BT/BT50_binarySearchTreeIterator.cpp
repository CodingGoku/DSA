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

// T : O(1)
// S : O(H) ... stack at each time has at max H elements ... left,left,left
class BSTIterator {
    private : stack<TreeNode*> myStack;

    public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    bool hasNext() {
        return !myStack.empty();
    }

    int next() {
        TreeNode* tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode->right); // push right's all left nodes
        return tmpNode->data;
    }

    private:
    void pushAll(TreeNode* root) {
        for(;root!=NULL; myStack.push(root), root = root->left); //push all the left nodes
    }
};

int main()
{
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(9);
    root->left->left->left = new TreeNode(1);
    root->left->right->left = new TreeNode(5);
    root->right->left->left = new TreeNode(8);
    root->left->right->left->left = new TreeNode(4);

    BSTIterator it(root);
    for(int i=0; i<10; i++) {
        cout<<"hasNext: "<<it.hasNext()<<"\n";
        cout<<"next: "<<it.next()<<"\n";
    }
    cout<<"hasNext: "<<it.hasNext()<<"\n";
    return 0;
}