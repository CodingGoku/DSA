#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& result, int row, int col, int initialColour, int newColour, int delRow[], int delCol[]) {
    result[row][col] = newColour;

    int n = result.size();
    int m = result[0].size();

    //traverse neighbours
    for(int i=0; i<4; i++) {
        int nrow = row+delRow[i];
        int ncol = col+delCol[i];
        if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && result[nrow][ncol] == initialColour) {
            dfs(result, nrow, ncol, initialColour, newColour, delRow, delCol);
        }
    }
}

// X = NxM
// T : O(X + Xx4)
// S : O(NxM) + O(NxM) ... recursive stack space
vector<vector<int>> floodFill(vector<vector<int>> image, int srow, int scol, int newColour) {
    int initialColour = image[srow][scol];
    if(initialColour == newColour) return image; // most important, otherwise gives infinite recursion

    vector<vector<int>> result = image;

    int delRow[] = {0,-1,0,1};
    int delCol[] = {-1,0,1,0};

    dfs(result, srow, scol, initialColour, newColour, delRow, delCol);
    return result;
}

int main()
{
    vector<vector<int>> image {{1,1,1},
                               {2,2,0},
                               {2,2,2}};

    int startingRow = 2;
    int startingCol = 0;
    int newColour = 3;

    vector<vector<int>> result = floodFill(image, startingRow, startingCol, newColour);
    for(auto i : result) {
        for(auto j : i) cout<<j<<" ";
        cout<<"\n";
    }
    return 0;
}