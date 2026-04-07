#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> size, parent;
    DisjointSet(int n) {
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUlp(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findUlp(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUlp(u);
        int ulp_v = findUlp(v);

        if(ulp_u == ulp_v) return; // there is no use

        if(size[ulp_v] > size[ulp_u]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }

        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

// T : n + 4 x alpha + elog(e) + n x k ... k = max emails per account
// S : n + e ... n = no. of accounts, e = unique emails
vector<vector<string>> mergeAccounts(vector<vector<string>>& accounts) {
    int n = accounts.size();
    unordered_map<string, int> map;
    DisjointSet ds1(n);

    for(int i=0; i<n; i++) {
        // start with index=1 as index 0 contains name and not the mail
        for(int j=1; j<accounts[i].size(); j++) {
            string mail = accounts[i][j];
            if(map.find(mail) == map.end()) { // if not present in map insert it
                map[mail] = i;
            }
            else {
                ds1.unionBySize(i, map[mail]); // as these 2 persons are the same person
            }
        }
    }

    vector<string> merged[n];
    for(auto it : map) {
        string mail = it.first;
        int node = ds1.findUlp(it.second);
        merged[node].push_back(mail);
    }

    vector<vector<string>> ans;
    for(int i=0; i<n; i++) {
        if(merged[i].size() == 0) continue;
        sort(merged[i].begin(),merged[i].end()); //sort emails by name
        vector<string> temp;
        temp.push_back(accounts[i][0]); // name of the person
        for(auto it : merged[i]) {
            temp.push_back(it); // mails of the person
        }

        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    vector<vector<string>> accounts = {{"John","j1@com","j2@com","j3@com"},
                                       {"John","j4@com"},
                                       {"Raj","r1@com","r2@com"},
                                       {"John","j1@com","j5@com"},
                                       {"Raj","r2@com","r3@com"},
                                       {"Mary","m1@com"}};
    
    vector<vector<string>> acc = mergeAccounts(accounts);
    for(auto it : acc) {
        for(auto i : it) cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}