#include <bits/stdc++.h>
using namespace std;

bool bipartiteComponent(int start, vector<int> adj[], vector<int> &colour) {
    queue<int> q;
    q.push(start);
    colour[start] = 0; // start colour is 0


    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        for(int i : adj[node]) {
            if(colour[i] == -1) { // not coloured
                q.push(i);
                colour[i] = !colour[node];
            }
            else if(colour[i] == colour[node]) return false; // not bipartite if adjacent nodes have same colour
        }
    }

    return true;
}

// T : O(V + 2E) ... same as bfs
// S : O(V)
bool isBipartiteGraph(int V, vector<int> adj[]) {
    vector<int> colour(V+1,-1);

    // for connected components
    for(int i=1; i<=V; i++) {
        if(colour[i] == -1) {
            if(!bipartiteComponent(i, adj, colour)) return false;
        }
    }
    return true;
}

int main()
{
    int n = 6;
    vector<int> adj[n+1];
    adj[0] = {};
    adj[1] = {2};
    adj[2] = {1,3,5};
    adj[3] = {2,4};
    adj[4] = {3,5,6};
    adj[5] = {2,4};
    adj[6] = {4};

    cout<<"isBipartite : "<<isBipartiteGraph(n, adj);
    return 0;
}