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

// we are following Level Order Traversal
vector<vector<int>> verticalTraversal(TreeNode* root) { // map stores in sorted order
    map<int, map<int, multiset<int>>> nodes; // vertical, level, val ... multiset arranges in sorted order and can have same values
    queue<pair<TreeNode*, pair<int, int>>> todo; // TreeNode*, vertical, level
    todo.push({root, {0,0}});
    while(!todo.empty()) {
        auto p = todo.front();
        todo.pop();
        TreeNode* node = p.first; // node
        int x = p.second.first; // vertical
        int y = p.second.second; // level
        nodes[x][y].insert(node->val); // in map nodes, insert node at vertical x and level y
        if(node->left) todo.push({node->left, {x-1, y+1}});
        if(node->right) todo.push({node->right, {x+1, y+1}});
    }

    vector<vector<int>> ans;
    for(auto p : nodes) { // p = {vertical,{level,val-multiset}}
        vector<int> col;
        // p.second is {level, multiset}
        for(auto q: p.second) { // q = {level,val-multiset} ...  q.second is the multiset
            col.insert(col.end(), q.second.begin(), q.second.end()); // insert the multiset
        }
        ans.push_back(col);

        /*
        p is a pair where: (vertical, (level,multiset))
        p.first is the vertical level
        p.second is a map(level, multiset)  map<int, multiset<int>> corresponding to levels and node values at that vertical level.

        q is a pair where: (level, multiset)
        q.first is the level
        q.second is a multiset<int> containing node values at the same vertical and horizontal level.
        */
    }
    return ans;
}

int main()
{

    return 0;
}