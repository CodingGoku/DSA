#include <bits/stdc++.h>
using namespace std;

// Recursion
// T : exponential O(2^n + 2^m)
// S : O(n + m)
int distSubseq(string s1, string s2, int i, int j)
{
    //base case
    if(j<0) return 1;
    if(i<0) return 0;

    if(s1[i] == s2[j]) return distSubseq(s1, s2, i-1, j-1) + distSubseq(s1, s2, i-1, j); // if element matches
    return distSubseq(s1, s2, i-1, j); // if it doesn't match
}

// Memoization
// T : O(n x m)
// S : O(n x m) + O(n + m) auxiliary stack space
int distSubseqMem(string s1, string s2, int i, int j, vector<vector<int>> dp)
{
    //base case
    if(j<0) return 1;
    if(i<0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]) return dp[i][j] = distSubseqMem(s1, s2, i-1, j-1, dp) + distSubseqMem(s1, s2, i-1, j, dp); // if element matches
    return dp[i][j] = distSubseqMem(s1, s2, i-1, j, dp); // if it doesn't match
}

// Tabulation
// T : O(n x m)
//
int distSubseqTab(string s1, string s2, int i, int j)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1,0)); // 1-based indexing

    //base case
    for(int i = 0; i<=n; i++) dp[i][0] = 1;
    for(int j = 1; j<=m; j++) dp[0][j] = 0; // SET j = 1 AS IN PREVIOUS LINE WE HAVE DONE j = 0 
                                            //... this line can also be omitted as everyting is already initialized to 0

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];   // i = i-1   &   j = j - 1   in if statement
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][m];
}

// Space Optimization
// T : O(n)
// S : O(n)
int distSubseqSO(string s1, string s2, int i, int j)
{
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(n+1,0), curr(n+1,0);

    //base case
    prev[0] = curr[0] = 1;
    // OMIT as colums were are not focusing on ...for(int j = 0; j<=m; j++) dp[0][j] = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s1[i-1] == s2[j-1]) curr[j] = prev[j-1] + prev[j]; // if element matches
            else curr[j] = prev[j]; // if it doesn't match
        }
        prev = curr;
    }
    return prev[m];
}

// Space Optimization
// T : O(n)
// S : O(n)
int distSubseq1SO(string s1, string s2, int i, int j)
{
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(n+1,0);

    //base case
    prev[0] = 1;
    // OMIT as colums were are not focusing on ...for(int j = 0; j<=m; j++) dp[0][j] = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s1[i-1] == s2[j-1]) prev[j] = prev[j-1] + prev[j]; // if element matches
            else prev[j] = prev[j]; // if it doesn't match
        }
        prev = prev;
    }
    return prev[m];
}

int main()
{
    string s1 = "babgbag", s2 = "bag";
    int i = s1.size()-1;
    int j = s2.size()-1;

    cout<<"recursion : "<<distSubseq(s1, s2, i, j)<<"\n";

    // dp[i+1][j+1]   i from 0 to i (last index)
    vector<vector<int>> dp(i+1,vector<int> (j+1,-1));
    cout<<"memoization : "<<distSubseqMem(s1, s2, i, j, dp)<<"\n";

    cout<<"tabulation : "<<distSubseqTab(s1, s2, i, j)<<"\n";

    cout<<"space optimization : "<<distSubseqSO(s1, s2, i, j)<<"\n"; 

    cout<<"single array space optimization : "<<distSubseq1SO(s1, s2, i, j)<<"\n"; 

    return 0;
}