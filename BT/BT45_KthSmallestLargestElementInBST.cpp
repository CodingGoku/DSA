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

// T : O(N)
// S : O(N) ... recursive stack space
void KthSmallest(TreeNode* root, int k, int& cnt, int& ans) {
    if(root == NULL) return;

    // inorder traversal LNR
    KthSmallest(root->left, k, cnt, ans);
    cnt++;
    if(cnt == k) ans = root->data;
    KthSmallest(root->right, k, cnt, ans);
}

void totalNodes(TreeNode* root, int& total) {
    if(root == NULL) return;

    totalNodes(root->left, total);
    total++;
    totalNodes(root->right, total);
}

void KthLargest(TreeNode* root, int k, int& cnt, int& ans) {
    int total;
    totalNodes(root, total);

    KthSmallest(root, total-k+1, cnt, ans);
}

int main()
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);
    root->left->left->right = new TreeNode(2);

    int cnt = 0;
    int ans = -1;
    KthSmallest(root, 3, cnt, ans);
    cout<<"Kth Smallest: "<<ans<<"\n";

    int total = 0;
    totalNodes(root, total);
    cout<<total;

    cnt = 0, ans = -1;
    KthLargest(root, 3,cnt, ans);
    cout<<"Kth Largest: "<<ans;
    return 0;
}