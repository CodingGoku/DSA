#include <bits/stdc++.h>
using namespace std;

// T : K x N + N
int gasStation(vector<int> arr, int k)
{
    int n = arr.size();
    // gas stations between each section of array
    vector<int> howMany (n-1,0);
    // insert k gas stations
    for(int i=1;i<=k;i++)
    {
        int maxIndex = -1, maxVal = -1;
        // travesrse the array to find the max gap
        for(int i=0;i<n - 1;i++)
        {
            int diff = arr[i+1] - arr[i];
            // new section length after inserting 1 gas station
            int sectionLength = diff/(howMany[i]+1);
            if(sectionLength > maxVal)
            {
                maxVal=sectionLength;
                maxIndex = i;
            }
        }
        howMany[maxIndex]++;
    }

    int maxVal = -1;
    // find the max gap after inserting gas stations
    for(int i=0;i<n-1;i++)
    {
        int diff = arr[i+1] - arr[i];
        // if 2 points are in a diff of 12 then 3 (2+1) sections wii be formed
        // of length 12/3 = 4 each (4+4+4)
        int newSectionLength = diff/(howMany[i]+1);
        maxVal = max(maxVal, newSectionLength);
    }
    return maxVal;
}

// Using priority queue
// T : N log N + K log N
// S : N - 1
int gas(vector<int> arr, int k)
{
    int n = arr.size();
    // gas stations between each section of array
    priority_queue<pair<long double, int>> pq; // (diff, index)

    // insert in pq
    for(int i=0;i<n-1;i++)
    {
        pq.push({arr[i+1]-arr[i],i});
    }

    vector<int> howMany (n-1,0);
    // insert k gas stations
    for(int i=1;i<=k;i++)
    {
        auto tp = pq.top();
        pq.pop();
        //we know that tp is the max distance ... as it is priority_queue
        // so we insert a gas station
        int sectionIndex = tp.second;
        howMany[sectionIndex]++;

        int diff = arr[sectionIndex+1] - arr[sectionIndex];
        int sectionLength = diff/(howMany[sectionIndex]+1);
        pq.push({sectionLength,sectionIndex});
    }
    return pq.top().first;
}

int main()
{
    vector<int> arr {1,13,17,23};
    int k = 5;
    cout<<gasStation(arr, k)<<"\n";
    cout<<gas(arr, k);
    return 0;
}