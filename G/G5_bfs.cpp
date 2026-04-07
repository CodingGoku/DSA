#include <bits/stdc++.h>
using namespace std;

// T : O(N) + O(2E) ... while loop runs for all nodes pops 1 element each time from queue -> O(N)
//                  ... for loop runs for each adjacency i.e. 1 with 2, 2 with 1, so on -> O(2E) in total for for loop
// S : O(3N) ... N for each of vis, q, bfs
vector<int> bfs(int V, vector<int> adj[]) {
    int vis[V] = {0}; // initially none visited
    vis[0] = 1; // first node is visited ... starting with node 0
    queue<int> q;
    q.push(0); // assuming we start with node 0

    vector<int> bfs;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto i : adj[node]) {
            if(!vis[i]) {
                vis[i] = 1;
                q.push(i);
            }
        }
    }

    return bfs;
}

int main()
{
    int n = 9; // vertex
    vector<int> adj[n+1]; // vector in each array element

    // if start with node 0
    adj[0].push_back(1);
    adj[1].push_back(0);

    // total 2 x E = 2 x 9 = 18
    adj[1].push_back(2);
    adj[1].push_back(6);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(2);
    adj[4].push_back(2);
    adj[4].push_back(5);
    adj[5].push_back(4);
    adj[5].push_back(8);
    adj[6].push_back(1);
    adj[6].push_back(7);
    adj[6].push_back(9);
    adj[7].push_back(6);
    adj[7].push_back(8);
    adj[8].push_back(5);
    adj[8].push_back(7);
    adj[9].push_back(6);

    vector<int> bf = bfs(n, adj);

    for(int i : bf) cout<<i<<" ";
    return 0;
}