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

void printVector(vector<int> v) {
    for(int i : v) cout<<i<<" ";
    cout<<"\n";
}

void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track) {
    queue<TreeNode*> queue;
    queue.push(root);
    while(!queue.empty()) {
        TreeNode* current  = queue.front();
        queue.pop();

        if(current->left) {
            parent_track[current->left] = current; // left's parent is current
            queue.push(current->left);
        }

        if(current->right) {
            parent_track[current->right] = current; // right's parent is current
            queue.push(current->right);
        }
    }
}

vector<int> distance(TreeNode* root, TreeNode* target, int K) {
    queue<TreeNode*> queue;
    unordered_map<TreeNode*, TreeNode*> parent_track; // node, parent
    unordered_map<TreeNode*, bool> visited;

    markParents(root, parent_track);

    // make sure to push target and not the root
    queue.push(target);
    visited[target] = true;

    int dist = 0;
    // BFS Traversal
    while(!queue.empty()) {
        if(dist++ == K) break; // dist will increment after next line as it is post increment
                               // now stack will have all nodes at dist == k

        int size = queue.size();
        for(int i=0; i<size; i++) {
            TreeNode* current = queue.front();
            queue.pop();

            //visit left
            if(current->left && !visited[current->left]) {
                queue.push(current->left);
                visited[current->left] = true;
            }

            //visit right
            if(current->right && !visited[current->right]) {
                queue.push(current->right);
                visited[current->right] = true;
            }

            //visit parent
            if(parent_track[current] && !visited[parent_track[current]]) {
                queue.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }

    vector<int> result;
    while(!queue.empty()) {
        TreeNode* current = queue.front();
        queue.pop();
        result.push_back(current->data);
    }

    return result;
}

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    vector<int> result = distance(root, root->left, 2);
    printVector(result);
    return 0;
}