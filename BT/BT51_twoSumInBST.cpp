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

// T : O(N) ... for 2 pointer
// S : O(2H) ... stack at each time has at max H elements ... we have 2 stacks for next and before
class BSTIterator {
    private : stack<TreeNode*> myStack;
    //reverse = true -> before
    //reverse = false -> next
    bool reverse = true;

    public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    bool hasNext() {
        return !myStack.empty();
    }

    int next() {
        TreeNode* tmpNode = myStack.top();
        myStack.pop();
        if(!reverse) pushAll(tmpNode->right); // push right's all left nodes
        else pushAll(tmpNode->left); //for before
        return tmpNode->data;
    }

    private:
    void pushAll(TreeNode* root) {
        for(;root!=NULL;) {
            myStack.push(root);
            if(!reverse) root = root->left; //push all the left nodes
            else root = root->right; //for before
        }
    }
};

bool findTarget(TreeNode* root, int k) {
    if(root == NULL) return false;
    BSTIterator l(root, false); // l -> next, reverse = false
    BSTIterator r(root, true); // r -> before, reverse = true

    int i = l.next();
    int j = r.next();
    while(i<j) {
        if(i + j == k) return true;
        else if(i + j < k) i = l.next();
        else j = r.next();
    }
    return false;
}

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

    cout<<findTarget(root, 16);
    return 0;
}