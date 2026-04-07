#include <bits/stdc++.h>
using namespace std;

//Recursion
// T: O(3^N)   3 ways at each point straight, left-diagonal, right-diagonal
// S: O(N)     depth of the recursion is N. lenght of the rows which recursion will cover
int f(int i, int j, vector<vector<int>> &matrix)
{
    if(j<0 || j>=matrix[0].size()) return -1e8; // going out of matrix .... and we are not returning INT_MIN as someting
                                                // is added to it and then INT_MIN + 1 is a greater number ~ INT_MAX
    if(i==0) return matrix[0][j]; // if in first row return matirx[0][j]

    int up = matrix[i][j]+f(i-1,j,matrix); // moving up
    int ld = matrix[i][j]+f(i-1,j-1,matrix); // moving left diagonal
    int rd = matrix[i][j]+f(i-1,j+1,matrix); // moving right diagonal

    return max(up,max(ld,rd));
}

//Memoization
// T: O(N x M)   N x M are the no. of states we will have at maximum
// S: O(N x M)     for the DP matrix  + O(N) for recursion stack space
int fMem(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> dp)
{
    if(j<0 || j>=matrix[0].size()) return -1e8; // going out of matrix .... and we are not returning INT_MIN as someting
                                                // is added to it and then INT_MIN + 1 is a greater number ~ INT_MAX
    if(i==0) return matrix[0][j]; // if in first row return matirx[0][j]

    if(dp[i][j]!=-1) return dp[i][j];

    int up = matrix[i][j]+fMem(i-1,j,matrix,dp); // moving up
    int ld = matrix[i][j]+fMem(i-1,j-1,matrix,dp); // moving left diagonal
    int rd = matrix[i][j]+fMem(i-1,j+1,matrix,dp); // moving right diagonal

    dp[i][j]=max(up,max(ld,rd));
    return dp[i][j];
}

//Tabulation
// T: O(N x M)    + O(M)  for selecting max among different end points
// S: O(N x M)       no recursion stack space
void fTab(vector<vector<int>> &matrix,int n,int m)
{
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int j=0;j<m;j++)
    {
        dp[0][j] = matrix[0][j]; // first row of matrix = first row of dp
    }

    for(int i=1;i<n;i++) // note : i starts with 1 not 0 as that is taken care of above
    {
        for(int j=0;j<m;j++)
        {
            //int up = matrix[i][j]+dp[i-1][j]; // moving up
            //int ld = matrix[i][j]+dp[i-1][j-1]; // moving left diagonal
            //int rd = matrix[i][j]+dp[i-1][j+1]; // moving right diagonal

            int up = matrix[i][j]+dp[i-1][j];
            int ld = matrix[i][j];
            if(j-1>=0) ld+=dp[i-1][j-1]; // should be inside matrix from left side
            else ld+= -1e8;
            int rd = matrix[i][j];
            if(j+1<m) rd+=dp[i-1][j+1]; // should be inside matrix from right side
            else rd+= -1e8;
            dp[i][j]=max(up,max(ld,rd));
        }
    }

    //tabulation
    int maxi=-1e8;
    for(int j=0;j<m;j++)
    {
        maxi = max(maxi,dp[n-1][j]); //calling from each element of last row
    }
    cout<<"using tabulation : "<<maxi<<"\n";
}

//Space Optimization
void fSO(vector<vector<int>> &matrix,int n,int m)
{
    vector<int> prev(m,0) , curr(m,0);
    for(int j=0;j<m;j++)
    {
        prev[j] = matrix[0][j]; // first row of matrix = first row of dp
    }

    for(int i=1;i<n;i++) // note : i starts with 1 not 0 as that is taken care of above
    {
        for(int j=0;j<m;j++)
        {
            int up = matrix[i][j]+prev[j];
            int ld = matrix[i][j];
            if(j-1>=0) ld+=prev[j-1]; // should be inside matrix from left side
            else ld+= -1e8;
            int rd = matrix[i][j];
            if(j+1<m) rd+=prev[j+1]; // should be inside matrix from right side
            else rd+= -1e8;
            curr[j]=max(up,max(ld,rd));
        }
        prev=curr;
    }

    //Space Optimization
    int maxi=-1e8;
    for(int j=0;j<m;j++)
    {
        maxi = max(maxi,prev[j]); //calling from each element of last row
    }
    cout<<"using Space Optimization : "<<maxi<<"\n";
}

int main()
{
    vector<vector<int>> matrix{
                {1,3,6,4},
                {4,6,2,3},
                {8,6,2,7},
                {4,7,3,5},
                {5,3,1,6}
            };
    
    int n = matrix.size(); // n -> rows
    int m = matrix[0].size(); // m -> columns
    int maxi = -1e8; // initially a small value
    
    //recursion
    for(int j=0;j<m;j++)
    {
        maxi = max(maxi,f(n-1,j,matrix)); //calling from each element of last row
    }
    cout<<"using recursion : "<<maxi<<"\n";

    //memoization
    maxi = -1e8;
    vector<vector<int>> dp(n,vector<int>(m,-1));
    for(int j=0;j<m;j++)
    {
        maxi = max(maxi,fMem(n-1,j,matrix,dp)); //calling from each element of last row
    }
    cout<<"using memoization : "<<maxi<<"\n";

    fTab(matrix,n,m);

    fSO(matrix,n,m);
    return 0;
}