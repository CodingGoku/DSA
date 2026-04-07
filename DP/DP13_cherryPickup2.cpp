#include <bits/stdc++.h>
using namespace std;

//Recursion
// T: O(3^N x 3^N)  3 ways for Alice and Bob each
// S: O(N)  lenght to cover is N , row size
int cherryPickup2(int i,int j1,int j2,int r,int c,vector<vector<int>> grid) // i is common for both Alice and Bob, only j differs
{
    //base case
    if(j1<0 || j2<0 || j1>=c || j2>=c) // if we go out of the matrix
    {
        return -1e8; // some min value to reject from answer and not INT_MIN as it is adding up and INT_MIN +1 will be INT_MAX
    }

    if(i==r-1) // if we are at the last row
    {
        if(j1==j2) return grid[i][j1]; // if both Alice and Bob are on same block then it is considered only once
        else return grid[i][j1] + grid[i][j2]; // if both are in a different block
    }

    int maxi = -1e8;
    for(int dj1 = -1; dj1<= +1; dj1++) //3 ways for Alice
    {
        for(int dj2 = -1; dj2<= +1; dj2++) // 3 ways for Bob
        {
            int value = 0;
            if(j1==j2) value = grid[i][j1]; // if both are on same block then value will be taken once
            else value = grid[i][j1] + grid[i][j2]; // value is some of both blocks of Alice and Bob
            value += cherryPickup2(i+1,j1+dj1,j2+dj2,r,c,grid);
            maxi = max(maxi,value);
        }
    }
    return maxi;
}

// Memoization
int cherryPickup2Mem(int i,int j1,int j2,int r,int c,vector<vector<int>> grid, vector<vector<vector<int>>> &dp) // i is common for both Alice and Bob, only j differs
{
    //base case
    if(j1<0 || j2<0 || j1>=c || j2>=c) // if we go out of the matrix
    {
        return -1e8; // some min value to reject from answer and not INT_MIN as it is adding up and INT_MIN +1 will be INT_MAX
    }

    if(i==r-1) // if we are at the last row
    {
        if(j1==j2) return grid[i][j1]; // if both Alice and Bob are on same block then it is considered only once
        else return grid[i][j1] + grid[i][j2]; // if both are in a different block
    }

    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];

    int maxi = -1e8;
    for(int dj1 = -1; dj1<= +1; dj1++) //3 ways for Alice
    {
        for(int dj2 = -1; dj2<= +1; dj2++) // 3 ways for Bob
        {
            int value = 0;
            if(j1==j2) value = grid[i][j1]; // if both are on same block then value will be taken once
            else value = grid[i][j1] + grid[i][j2]; // value is some of both blocks of Alice and Bob
            value += cherryPickup2(i+1,j1+dj1,j2+dj2,r,c,grid);
            maxi = max(maxi,value);
        }
    }

    dp[i][j1][j2] = maxi;
    return dp[i][j1][j2];
}

int cherryPickup2Tab(int n, int m, vector<vector<int>> &grid) // n -> rows ,  m -> columns
{
    // dp[r][c][c]
    vector<vector<vector<int>>> dp(n,vector<vector<int>> (m, vector<int>(m,0)));
    //base case
    for(int j1=0;j1<m;j1++)
    {
        for(int j2=0;j2<m;j2++)
        {
            if(j1==j2) dp[n-1][j1][j2] = grid[n-1][j1]; // n-1 for last row for this base case
            else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
        }
    }

    for(int i=n-2;i>=0;i--) // starts with n-2 as n-1 is covered in base case
    {
        for(int j1=0;j1<m;j1++)
        {
            for(int j2=0;j2<m;j2++)
            {
                // now copy-paste whatever you wrote in the recurrence in these nested for loops
                int maxi = -1e8;
                for(int dj1 = -1; dj1<= +1; dj1++) //3 ways for Alice
                {
                    for(int dj2 = -1; dj2<= +1; dj2++) // 3 ways for Bob
                    {
                        int value = 0;
                        if(j1==j2) value = grid[i][j1]; // if both are on same block then value will be taken once
                        else value = grid[i][j1] + grid[i][j2]; // value is some of both blocks of Alice and Bob

                        if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m) //check out of bound condition
                            value += dp[i+1][j1+dj1][j2+dj2];
                        else
                            value += -1e8; // reject from answer by adding a large negative value
                        maxi = max(maxi,value);
                    }
                }

                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][m-1]; //base value of recursion where i=0 j1=0 j2=m-1
}


//Space Optimization
// 1D -> two variables
// 2D -> 1D DP
// 3D -> 2D

int cherryPickup2SO(int n, int m, vector<vector<int>> &grid) // n -> rows ,  m -> columns
{
    // dp[r][c][c]

    vector<vector<int>> front(m,vector<int> (m,0)); //previous
    vector<vector<int>> curr(m,vector<int> (m,0)); //current

    // now convert dp[n-1] -> front
    // dp[i+1] -> front
    // dp[i] -> curr
    // dp[0] -> front

    //base case
    for(int j1=0;j1<m;j1++)
    {
        for(int j2=0;j2<m;j2++)
        {
            if(j1==j2) front[j1][j2] = grid[n-1][j1]; // n-1 for last row for this base case
            else front[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
        }
    }

    for(int i=n-2;i>=0;i--) // starts with n-2 as n-1 is covered in base case
    {
        for(int j1=0;j1<m;j1++)
        {
            for(int j2=0;j2<m;j2++)
            {
                // now copy-paste whatever you wrote in the recurrence in these nested for loops
                int maxi = -1e8;
                for(int dj1 = -1; dj1<= +1; dj1++) //3 ways for Alice
                {
                    for(int dj2 = -1; dj2<= +1; dj2++) // 3 ways for Bob
                    {
                        int value = 0;
                        if(j1==j2) value = grid[i][j1]; // if both are on same block then value will be taken once
                        else value = grid[i][j1] + grid[i][j2]; // value is some of both blocks of Alice and Bob

                        if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m) //check out of bound condition
                            value += front[j1+dj1][j2+dj2];
                        else
                            value += -1e8; // reject from answer by adding a large negative value
                        maxi = max(maxi,value);
                    }
                }

                curr[j1][j2] = maxi;
            }
        }
        // just before last for loop
        front = curr;
    }
    return front[0][m-1]; //base value of recursion where i=0 j1=0 j2=m-1
}

int main()
{
    vector<vector<int>> grid{
                            {3,1,2,4,6},
                            {5,7,4,5,3},
                            {8,2,4,2,7},
                            {6,3,7,2,1},
                            {3,7,5,9,1}
                        };
    
    int r = grid.size();
    int c =grid[0].size();

    //recursion
    cout<<"Recursion : "<<cherryPickup2(0,0,c-1,r,c,grid)<<"\n";
    //memoization
    // dp[r][c][c]   ... 3D DP
    vector<vector<vector<int>>> dp(r, vector<vector<int>> (c, vector<int> (c,-1)));
    cout<<"Memoization : "<<cherryPickup2Mem(0,0,c-1,r,c,grid,dp)<<"\n";
    cout<<"Tabulation : "<<cherryPickup2Tab(r,c,grid)<<"\n";
    cout<<"Space Optimization : "<<cherryPickup2SO(r,c,grid)<<"\n";
    return 0;
}