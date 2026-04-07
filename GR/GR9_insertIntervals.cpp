#include <bits/stdc++.h>
using namespace std;

// T: O(N)
// S: O(N)
vector<pair<int, int>> insertIntervals(vector<pair<int, int>>& intervals, pair<int, int>& newInterval) {
    int n = intervals.size();
    int i=0;

    vector<pair<int, int>> res;

    // insert left non overlapping intervals
    while(i<n && newInterval.first > intervals[i].second) {
        res.push_back({intervals[i]});
        i++;
    }

    // insert overlapping interval
    while(i<n && intervals[i].first <= newInterval.second) {
        newInterval.first = min(intervals[i].first, newInterval.first); // min of first element of both pairs
        newInterval.second = max(intervals[i].second, newInterval.second); // max of last element of both pairs
        i++;
    }
    res.push_back({newInterval.first, newInterval.second});
    
    // insert right non overlapping intervals
    while(i<n && newInterval.second < intervals[i].first) {
        res.push_back({intervals[i]});
        i++;
    }

    return res;
}

int main()
{
    vector<pair<int, int>> intervals = {{1,2},{3,4},{5,7},{8,10},{12,16}};
    pair<int, int> newInterval = {6,8};

    vector<pair<int, int>> res = insertIntervals(intervals, newInterval);
    cout<<"new intervals: ";
    for(auto it: res) {
        cout<<"("<<it.first<<", "<<it.second<<"), ";
    }

    return 0;
}