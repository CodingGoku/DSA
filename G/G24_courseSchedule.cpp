#include <bits/stdc++.h>
using namespace std;

// T : O(V + E) ... BFS for directed graph
// S : O(V)
bool courseSchedule(int V, vector<pair<int, int>>& prerequisites) {
    vector<int> adj[V];
    for(auto i : prerequisites) adj[i.second].push_back(i.first); // as second should be completed first


    // Topological Sort using BFS
    int indegree[V] = {0};

    for(int i=0; i<V; i++) {
        for(auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    vector<int> schedule;
    // we only push in queue when a node's indegree = 0
    for(int i=0; i<V; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        schedule.push_back(node);

        // this node is in topological sort, so remove indegree coming from this node
        for(auto it : adj[node]) {
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }

    if(schedule.size() == V) {
        cout<<"Course Schedule: ";
        for(int i : schedule) cout<<i<<" ";
        return true;
    }
    else cout<<"Courses cannot be scheduled due to cyclic dependency";
    return false;
}

int main()
{
    int V = 4;

    vector<pair<int, int>> prerequisites = {{1,0}, // to complete 1, 0 should be completed first
                                            {2,1},
                                            {3,2}};

    courseSchedule(V, prerequisites);

    V = 5;
    prerequisites = {{2,1}, // to complete 2, 1 should be completed first
                     {3,4},
                     {4,2},
                     {1,4}};
    cout<<"\n\n";
    courseSchedule(V, prerequisites);
    return 0;
}