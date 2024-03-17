#include <bits/stdc++.h>
using namespace std;

pair<int,int> binarySearch(vector<vector<int>> arr, int i, int target)
{
    int low = 0, high = arr[0].size()-1;
    while(arr[i][low]<=arr[i][high])
    {
        int mid = low + (high - low)/2;

        if(arr[i][mid] == target) return make_pair(i,mid);

        else if(arr[i][mid] > target) high = mid - 1;
        else low = mid + 1;
    }
    return make_pair(-1,-1);
}

// T : N + log M     ....  as binary search is only performed once
pair<int,int> search(vector<vector<int>> arr, int target)
{
    int n = arr.size();
    int m = arr[0].size();

    for(int i=0;i<n;i++)
    {
        if(target>=arr[i][0] && target<=arr[i][m-1])
        {
            return binarySearch(arr, i, target);
        }
    }
    return make_pair(-1,-1);
}

// OPTIMIZED
// T : log (N x M)
pair<int,int> BS(vector<vector<int>> arr, int target)
{
    int n = arr.size();
    int m = arr[0].size();
    int low = 0, high = n*m -1;
    while(low<=high)
    {
        int mid = low + (high - low)/2;
        int row = mid/m;
        int col = mid%m;

        if(arr[row][col] == target) return make_pair(row,col);

        else if(arr[row][col] < target) low = mid + 1;

        else high = mid - 1;
    }
    return make_pair(-1,-1);
}

int main()
{
    vector<vector<int>> arr {{1,3,5,8,11},
                             {12,13,15,16,19},
                             {21,22,24,27,29},
                             {33,37,41,47,52},
                             {63,72,73,79,80}};

    pair<int,int> p = search(arr,27);
    cout<<"row : "<<p.first<<"   column : "<<p.second<<"\n\n";
    //OPTIMIZED
    p = BS(arr,27);
    cout<<"row : "<<p.first<<"   column : "<<p.second<<"\n\n";
    return 0;
}