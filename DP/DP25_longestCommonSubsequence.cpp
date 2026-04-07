#include <bits/stdc++.h>
using namespace std;

// Recursion
// T : exponential ... O(2^n x 2^m) ... 2^n subsequence for s1 and 2^m subsequence for s2
int lcs(string &s1, string &s2, int ind1, int ind2)
{
    //base case
    if(ind1<0 || ind2<0) return 0;

    if(s1[ind1] == s2[ind2]) return 1 + lcs(s1, s2, ind1-1, ind2-1); // if match then decrement both indexes
    return max(lcs(s1, s2, ind1-1, ind2),lcs(s1, s2, ind1, ind2-1)); // else if not match then decrement them seperately then take the max value of them
}

// Memoization
// T : O(N x M)
// S : O(N x M) + O(N + M) recursion stack space
int lcsMem(string &s1, string &s2, int ind1, int ind2, vector<vector<int>> dp)
{
    //base case
    if(ind1<0 || ind2<0) return 0;

    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

    if(s1[ind1] == s2[ind2]) dp[ind1][ind2] = 1 + lcs(s1, s2, ind1-1, ind2-1); // if match then decrement both indexes
    dp[ind1][ind2] = max(lcs(s1, s2, ind1-1, ind2),lcs(s1, s2, ind1, ind2-1)); // else if not match then decrement them seperately then take the max value of them

    return dp[ind1][ind2];
}

// Tabulation
int lcsTab(string &s1,string &s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    //base case
    for(int i = 0; i<=n; i++) dp[i][0] = 0;
    for(int j = 0; j<=n; j++) dp[0][j] = 0;

    for(int ind1 = 1; ind1 <= n; ind1++)
    {
        for(int ind2 = 1; ind2 <= m; ind2++)
        {
             if(s1[ind1-1] == s2[ind2-1]) dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else dp[ind1][ind2] = max(dp[ind1-1][ind2],dp[ind1][ind2-1]); // ADD ELSE HERE as in recursion there was no need of else as the previous statement got returned
        }
    }
    return dp[n][m];
}

// Space Optimization
int lcsSO(string &s1,string &s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m+1,0), curr(m+1,0);
    //base case
    for(int i = 0; i<=n; i++) prev[0] = 0;
    // OMIT THIS as column will not be there for(int j = 0; j<=n; j++) dp[0][j] = 0;

    for(int ind1 = 1; ind1 <= n; ind1++)
    {
        for(int ind2 = 1; ind2 <= m; ind2++)
        {
             if(s1[ind1-1] == s2[ind2-1]) curr[ind2] = 1 + prev[ind2-1];
            else curr[ind2] = max(prev[ind2],curr[ind2-1]); // ADD ELSE HERE as in recursion there was no need of else as the previous statement got returned
        }
        prev = curr;
    }
    return prev[m];
}

int main()
{
    string s1 = "adcbc", s2 = "dcadb";
    int n1 = s1.size();
    int n2 = s2.size();

    cout<<"recursion : "<<lcs(s1,s2,n1-1,n2-1)<<"\n";

    // dp[n1][n2] ... n1 from 0 -> n1-1   and   n2 from 0 -> n2-2
    vector<vector<int>> dp(n1,vector<int>(n2,-1));
    cout<<"memoization : "<<lcsMem(s1, s2, n1-1, n2-1, dp)<<"\n";

    cout<<"tabulation : "<<lcsTab(s1, s2)<<"\n";

    cout<<"space optimization : "<<lcsSO(s1, s2)<<"\n";
    return 0;
}