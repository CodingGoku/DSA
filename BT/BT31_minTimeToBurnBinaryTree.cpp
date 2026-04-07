#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int d) {
        data  = d;
        left = right = NULL;
    }
};

void mark_parents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track) {
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        if(current->left) {
            parent_track[current->left] = current;
            q.push(current->left);
        }

        if(current->right) {
            parent_track[current->right] = current;
        }
    }
}

int minTimeToBurn(TreeNode* root, TreeNode* target) {
    unordered_map<TreeNode*, TreeNode*> parent_track;

    mark_parents(root, parent_track);

    queue<TreeNode*> q;
    q.push(target); // remember to push target and not root

    unordered_map<TreeNode*, bool> visited;
    visited[target] = true;
    int time = 0; // time/level/distance same thing

    // in the end we will have nodes in queue which is burnt
    // and all it's neighbours are already burnt so we are
    // using burnt to only consider the time till we are burning
    // and not the end part when we are done burning but still traversing
    bool burnt;

    // burn all neighbours ... current queue has all neighbours
    // that are goint to be burnt at the same time
    while(!q.empty()) {
        int size = q.size();

        burnt = false; //burn for each time t

        for(int i=0; i<size; i++) {
            TreeNode* current = q.front();
            q.pop();

            //visit left
            if(current->left && !visited[current->left]) {
                q.push(current->left);
                visited[current->left] = true;
                burnt = true;
            }

            //visit right
            if(current->right && !visited[current->right]) {
                q.push(current->right);
                visited[current->right] = true;
                burnt = true;
            }

            //visit parent
            if(parent_track[current] && !visited[parent_track[current]]) {
                q.push(parent_track[current]);
                visited[parent_track[current]];
                burnt = true;
            }
        }

        if(burnt) time++;
    }

    return time;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->right = new TreeNode(7);

    TreeNode* target = root->left; // 2
    cout<<"Min time to burn binary tree : "<<minTimeToBurn(root, target);
    return 0;
}