#include <bits/stdc++.h>
using namespace std;

// T : n + m   ... worst case if element is bottom left ... we go complete down and complete left
pair<int,int> search(vector<vector<int>> arr, int target)
{
    int n = arr.size();
    int m = arr[0].size();
    
    int row = 0, col = m-1; // first row, last column
    while(row<n && col>=0)
    {
        if(arr[row][col] == target) return make_pair(row,col);

        else if(arr[row][col] < target) row++;
        else col--;
    }
    return make_pair(-1,-1);
}

int main()
{
    vector<vector<int>> arr {{1,4,7,11,15},
                            {2,5,8,12,19},
                            {3,6,9,16,22},
                            {10,13,14,17,24},
                            {18,21,23,26,30}};

    pair<int,int> p = search(arr,18);
    cout<<"row : "<<p.first<<"   column : "<<p.second<<"\n\n";
    return 0;
}