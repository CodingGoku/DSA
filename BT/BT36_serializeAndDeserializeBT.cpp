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
// S : O(N) ... queue
string serialize(TreeNode* root) {
    string s = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* currNode = q.front();
        q.pop();

        if(currNode == NULL) s+= "#,";
        else s+= to_string(currNode->data) + ",";

        if(currNode != NULL) {
            q.push(currNode->left);
            q.push(currNode->right);
        }
    }
    cout<<s;

    return s;
}

// T : O(N)
// S : O(N) ... queue
TreeNode* deserialize(string data) {
    if(data.size() == 0) return NULL;

    stringstream s(data);
    string str;
    getline(s,str, ',');
    TreeNode* root = new TreeNode(stoi(str));
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode* currNode = q.front();
        q.pop();

        //node's left
        getline(s, str, ',');
        if(str == "#") currNode->left = NULL;
        else {
            TreeNode* leftnode = new TreeNode(stoi(str));
            currNode->left = leftnode;
            q.push(leftnode);
        }

        //node's right
        getline(s, str, ',');
        if(str == "#") currNode->right = NULL;
        else {
            TreeNode* rightnode = new TreeNode(stoi(str));
            currNode->right = rightnode;
            q.push(rightnode);
        }
    }

    return root;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(13);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    printTree(root);
    string s = serialize(root);

    cout<<"\n";
    root = deserialize(s);
    printTree(root);
    return 0;
}