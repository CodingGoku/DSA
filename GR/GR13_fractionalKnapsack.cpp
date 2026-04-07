#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int>& i1, pair<int, int>& i2) {
    return double(i1.first)/i1.second > double(i2.first)/i2.second;
}

// T: O(NlogN + N)
// S: O(1)
double fractionalKnapsack(vector<pair<int, int>>& items, int wt) {
    int n = items.size();
    sort(begin(items), end(items), comp);

    double totalVal = 0;
    for(int i=0; i<n; i++) {
        if(items[i].second < wt) {
            totalVal += items[i].first;
            wt -= items[i].second;
        }
        else {
            totalVal += (double(items[i].first)/items[i].second)*wt;
            break;
        }
    }

    return totalVal;
}

int main()
{
    vector<pair<int, int>> items = {{100,20}, {60,10}, {100,50}, {200,50}};
    int wt = 90;

    cout<<fractionalKnapsack(items, wt)<<endl;

    return 0;
}