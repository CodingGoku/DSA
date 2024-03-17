#include <bits/stdc++.h>
using namespace std;

int blackBox(vector<vector<int>> mat, int mid)
{
    int cnt = 0;
    // count the numbers <= mid in matrix
    for(int i = 0; i< mat.size(); i++)
    {
        cnt += upper_bound(mat[i].begin(), mat[i].end(), mid) - begin(mat[i]);
    }
    return cnt;
}

int median(vector<vector<int>> mat)
{
    int n = mat.size();
    int m = mat[0].size();

    int req = (n*m)/2;
    int low, high;

    for(int i=0; i<n; i++)
    {
        low = min(low, mat[i][0]);
        high = max(high, mat[i][m-1]);
    }

    while(low<=high)
    {
        int mid = low + (high - low)/2;
        int smallerEquals = blackBox(mat,mid);
        if(smallerEquals <= req) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

int main()
{
    vector<vector<int>> mat {{1,5,7,9,11},
                             {2,3,4,5,10},
                             {9,10,12,14,16}};
    cout<<median(mat);
    return 0;
}