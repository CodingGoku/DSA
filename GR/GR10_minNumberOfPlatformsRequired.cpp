#include <bits/stdc++.h>
using namespace std;

// T: O(N^2)
// S: O(1)
int minPlatforms(vector<int>& arrival, vector<int>& departure) {
    int n = arrival.size();
    int maxCnt = 0;

    for(int i=0; i<n; i++) {
        int cnt = 1;
        for(int j=i+1; j<n; j++) {
            if(arrival[j] <= departure[i]) cnt++;
        }
        maxCnt = max(maxCnt, cnt);
    }

    return maxCnt;
}

// T: O(NlogN + N)
// S: O(1)
int minPlatformsOP(vector<int>& arrival, vector<int>& departure) {
    int n = arrival.size();
    sort(begin(arrival), end(arrival));
    sort(begin(departure), end(departure));
    int i=0, j=0, cnt=0, maxCnt=0;

    while(i < n) { // as we are only bothered by arrival on platform
        if(arrival[i] < departure[j]) {
            cnt++;
            i++;
        }
        else {
            cnt--;
            j++;
        }

        maxCnt = max(maxCnt, cnt);
    }

    return maxCnt;
}

int main()
{
    vector<int> arrival   = {900, 945, 955, 1100, 1500, 1800};
    vector<int> departure = {920, 1200, 1130, 1150, 1900, 2000};

    cout<<minPlatforms(arrival, departure)<<endl;

    cout<<minPlatformsOP(arrival, departure)<<endl;

    return 0;
}