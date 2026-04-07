#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b) {
    return a.second.first < b.second.first; // Sort meeting by end time
}

// T: O(2N + NlogN)
// S: O(3N)
int nonOverlapping(vector<int>& start, vector<int>& end) {
    int n = start.size();
    vector<pair<int, pair<int, int>>> arr; // (start, end, meeting no.)

    // store (start, end, meeting no.)
    for(int i=0; i<n; i++) {
        arr.push_back({start[i],{end[i], i+1}});
    }

    sort(arr.begin(), arr.end(), comp);

    int cnt = 1, freeTime = arr[0].second.first; // end of first meeting after sorting
    vector<int> ds;
    ds.push_back(arr[0].second.second); // meeting number of first meeting after sorting

    for(int i=1; i<n; i++) {
        if(arr[i].first >= freeTime) { // start of next meeting >= end of last meeting
            cnt++;
            ds.push_back(arr[i].second.second);
            freeTime = arr[i].second.first; // end time of this meeting
        }
    }

    return n - cnt; // total meetings - nonOverlapping meetings
}

int main()
{
    vector<int> start = {0,3,1,5,5,7};
    vector<int> end = {5,4,2,9,7,9};
    
    cout<<"Minimum meetings removed to make non overlapping: "<<nonOverlapping(start, end);
    return 0;
}