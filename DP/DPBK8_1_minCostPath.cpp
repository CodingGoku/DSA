#include <bits/stdc++.h>
using namespace std;

//Recursion - O(2^N) exponential
int minCostPath(vector<vector<int>> cost,int m,int n)
{
    //base cases
    if(m==0 && n==0) return cost[0][0]; // when m and n both reach 0 then return
    if(m==0 && n!=0) return cost[0][n]+minCostPath(cost,0,n-1); // when we are at the 0 th row but column is not 0 we try to move towards [0][0]
    if(m!=0 && n==0) return cost[m][0]+minCostPath(cost,m-1,0); // when we are at the 0 th column but row is not 0 we try to move towards [0][0]

    int left=cost[m][n]+minCostPath(cost,m,n-1);
    int up=cost[m][n]+minCostPath(cost,m-1,n);

    return min(left,up);
}


//Memoization
int minCostPathMem(vector<vector<int>> cost,int m,int n,vector<vector<int>> dp)
{
    //base cases
    if(m==0 && n==0) return cost[0][0]; // when m and n both reach 0 then return
    if(m==0 && n!=0) return cost[0][n]+minCostPathMem(cost,0,n-1,dp); // when we are at the 0 th row but column is not 0 we try to move towards [0][0]
    if(m!=0 && n==0) return cost[m][0]+minCostPathMem(cost,m-1,0,dp); // when we are at the 0 th column but row is not 0 we try to move towards [0][0]
    if(dp[m][n]!=-1) return dp[m][n];


    int left=cost[m][n]+minCostPath(cost,m,n-1);
    int up=cost[m][n]+minCostPath(cost,m-1,n);

    return dp[m][n]=min(left,up);
}

//Tabulation - O(N^2)
// each cell of dp stores minimum cost to reach that cell from (0,0)
int minCostPathTab(vector<vector<int>> cost,int m,int n)
{
    vector<vector<int>> dp(m,vector<int>(m,0));

    dp[0][0]=cost[0][0];
    for(int i=1;i<n;i++) dp[0][i]=cost[0][i]+dp[0][i-1]; //Row - only one way to reach elements in first row
    for(int j=1;j<m;j++) dp[j][0]=cost[j][0]+dp[j-1][0]; //Column - only onw way to reach elements in first column

    for(int i=1;i<m;i++) // since first row is done we now start from the second row i.e. index 1
    {
        for(int j=1;j<n;j++) // since first column is done we now start from the second column i.e. index 1
        {
            int left=cost[i][j]+dp[i][j-1];
            int up=cost[i][j]+dp[i-1][j];
            dp[i][j]=min(left,up);
        }
    }
    return dp[m-1][n-1];
}

int main()
{
    vector<vector<int>> cost {{0,1,2,0},
                              {1,2,1,1},
                              {2,0,0,2},
                              {2,2,2,0}};
    int m=cost.size(); //rows
    int n=cost[0].size(); //columns

    cout<<minCostPath(cost,m-1,n-1)<<"\n";

    vector<vector<int>> dp(m,vector<int>(n,-1));
    cout<<minCostPathMem(cost,m-1,n-1,dp)<<"\n";

    cout<<minCostPathTab(cost,m,n)<<"\n";
    return 0;
}