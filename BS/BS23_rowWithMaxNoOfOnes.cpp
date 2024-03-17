#include <bits/stdc++.h>
using namespace std;

// n log2 m
int maxOnes(vector<vector<int>> arr)
{
    int n = arr.size(); //rows
    int m = arr[0].size(); // columns

    int cnt_max = 0, index = -1;
    for(int i=0; i<n; i++)
    {
        int cnt = 0;
        int first_occurence_of_1 = lower_bound(begin(arr[i]),end(arr[i]),1) - begin(arr[i]);
        cnt = m - first_occurence_of_1;

        if(cnt > cnt_max)
        {
            cnt_max = cnt;
            index = i;
        }
    }
    return index;
}

int main()
{
    vector<vector<int>> arr {
        {0,0,1,1,1},
        {0,0,0,0,1},
        {0,1,1,1,1},
        {0,0,0,1,1},
        {0,0,0,0,0}
    };
    cout<<maxOnes(arr);
    return 0;
}