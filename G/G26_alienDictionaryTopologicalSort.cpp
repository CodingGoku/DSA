#include <bits/stdc++.h>
using namespace std;

string alienDictionary(vector<string> dict, int n, int k) { // k->alphabets, n-words
    vector<int> adj[k];

    // creating adj matrix
    for(int i=0; i<n-1; i++) {
        string s1 = dict[i];
        string s2 = dict[i+1];
        int len = min(s1.size(), s2.size());

        for(int ptr=0; ptr<len; ptr++) {
            if(s1[ptr] != s2[ptr]) { // if char i of word1 is different from char i of word2
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a'); // a -> 0 ... z -> 25
                break; // we want only first mis-match
            }
        }
    }

    // Topological Sort
    int indegree[k] = {0};

    for(int i=0; i<k; i++) {
        for(int neighbour : adj[i]) {
            indegree[neighbour]++;
        }
    }

    queue<int> q;
    for(int i=0; i<k; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    vector<int> topo;
    while(!q.empty()) {
        int node = q.front();
        q.pop();

        topo.push_back(node);
        // as node is added to topo, remove indegree edges coming from this node
        for(int neighbour : adj[node]) {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0) q.push(neighbour);
        }
    }

    string res = "";
    for(int i : topo) {
        res = res + char(i+'a');
    }

    return res;
}

int main()
{
    vector<string> dict = {"baa", "abcd", "abca", "cab", "cad"};
    int k = 5;
    int n = 5;
    cout<<alienDictionary(dict, n, k);
    return 0;
}