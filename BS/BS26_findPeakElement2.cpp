#include <bits/stdc++.h>
using namespace std;

int maxIndex(vector<vector<int>> mat, int n, int m, int col)
{
    int maxi = -1, index;
    for(int i=0; i<n; i++)
    {
        if(mat[i][col]>maxi)
        {
            maxi = mat[i][col];
            index = i;
        }
    }
    return index;
}

// T : log(m) x n
// S : O(1)
vector<int> findPeak(vector<vector<int>> mat)
{
    int n = mat.size();
    int m = mat[0].size();
    // using BS to find col
    int low = 0, high = m - 1;
    while(low<=high)
    {
        int mid = low + (high - low)/2;
        int rowIndex = maxIndex(mat,n,m,mid);

        int left = mid-1 >= 0 ? mid - 1 : -1;
        int right = mid+1 < m ? mid + 1 : -1;

        if(mat[rowIndex][mid] > mat[rowIndex][left] && mat[rowIndex][mid] > mat[rowIndex][right]) return {rowIndex, mid};

        else if(mat[rowIndex][mid] < mat[rowIndex][left]) high = mid - 1;

        else low = mid + 1;
    }
    return {-1,-1};
}

int main()
{

    return 0;
}