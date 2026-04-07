#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b) {
    return a.second.second > b.second.second; // Sort jobs by profit
}

// T: O(NlogN + N x maxDeadline)
// S: O(maxDeadline)
pair<int, int> jobSequencing(vector<pair<int,pair<int,int>>>& jobs) { // id, deadline, profit
    int n = jobs.size();

    sort(begin(jobs), end(jobs), comp);
    int totalProfit = 0, cnt = 0, maxDeadline = -1;
    for(int i=0; i<n; i++) maxDeadline = max(maxDeadline, jobs[i].second.first);

    vector<int> hash(maxDeadline+1, -1); // for storing job id for that day, leaving day 0 empty as there is no such day 0
    for(int i=0; i<n; i++) { // check for each job starting from highest profit job
        int deadline = jobs[i].second.first;
        for(int j = deadline; j>0; j--) { // assign job to whichever day is empty starting from it's deadline to day1
            if(hash[j] == -1) {
                cnt++;
                hash[j] = jobs[i].first; // assign the job id to that day
                totalProfit += jobs[i].second.second;
                break; // this job is assigned
            }
        }
    }

    return {cnt, totalProfit};
}

int main()
{
    vector<pair<int,pair<int,int>>> jobs = {{1,{4,40}}, {2,{1,10}}, {3,{1,40}}, {4,{1,30}}};
    pair<int, int> result = jobSequencing(jobs);
    cout<<"count: "<<result.first<<endl;
    cout<<"profit: "<<result.second<<endl;

    return 0;
}