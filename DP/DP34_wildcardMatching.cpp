#include <bits/stdc++.h>
using namespace std;

// Recursion
// T : exponential
// S : O(N + M) auxiliary stack space

bool wildCard(string s1, string s2, int i, int j)
{
    //base case
    if(i<0 && j<0) return true; // if both index reach -1 at the same time, string match
    if(i<0 && j>=0) return false; // string1 is finished and string2 is left
    if(j<0 && i>=0) // if string2 is finished
    {
        for(int ii=0; ii<=i;ii++) // if complete s1 is now left with only '*'s then true (as * can also mean 0/null)
        {
            if(s1[ii]!='*') return false; // else if not '*' return false
        }
        return true;
    }

    if(s1[i] == s2[j] || s1[i] == '?') return wildCard(s1, s2, i-1, j-1); // if match move both index by 1 ( ? means 1 match )

    if(s1[i] == '*') return wildCard(s1, s2, i-1, j) | wildCard(s1, s2, i, j-1); // either take * value as 0 or 1 (move i or j by 1)

    return false;
}

// Memoization
// T : O(N x M)
// S : O(N x M) + O(N + M) auxiliary stack space
bool wildCardMem(string s1, string s2, int i, int j, vector<vector<int>>& dp)
{
    //base case
    if(i<0 && j<0) return true; // if both index reach -1 at the same time, string match
    if(i<0 && j>=0) return false; // string1 is finished and string2 is left
    if(j<0 && i>=0) // if string2 is finished
    {
        for(int ii=0; ii<=i;ii++) // if complete s1 is now left with only '*'s then true (as * can also mean 0/null)
        {
            if(s1[ii]!='*') return false; // else if not '*' return false
        }
        return true;
    }

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j] || s1[i] == '?') return dp[i][j] = wildCardMem(s1, s2, i-1, j-1, dp); // if match move both index by 1 ( ? means 1 match )

    if(s1[i] == '*') return dp[i][j] = wildCardMem(s1, s2, i-1, j, dp) | wildCardMem(s1, s2, i, j-1, dp); // either take * value as 0 or 1 (move i or j by 1)

    dp[i][j] = false;
    return dp[i][j];
}

// Tabulation
// T : O(N x M)
// S : O(N x M)
bool wildCardTab(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<bool>> dp(n+1, vector<bool>(m+1,false)); // 1-based indexing so n+1 and m+1 instead of n and m

    //base case
    dp[0][0] = true;
    for(int j = 1; j<=m; j++) dp[0][j] = false; // j = 0 done in previous line
    bool flag = true; // flag for * in string
    for(int i = 1; i<=n; i++)
    {
        for(int ii=1; ii<=i;ii++) // ii starts from 1 now not 0
        {
            if(s1[ii]!='*') flag = false;
            break;
        }
        dp[i][0] = flag;
    }

    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=m; j++)
        {
            if(s1[i-1] == s2[j-1] || s1[i-1] == '?') dp[i][j] = dp[i-1][j-1]; // if match move both index by 1 ( ? means 1 match )

            else if(s1[i-1] == '*') dp[i][j] = dp[i-1][j] | dp[i][j-1]; // either take * value as 0 or 1 (move i or j by 1)

            else dp[i][j] = false;
        }
    }
    return dp[n][m];
}

// Space Optimization
// T : O(N x M)
// S : O(M)
bool wildCardSO(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<bool> prev (m+1, false), curr (m+1, false);

    //base case
    prev[0] = true;
    // can be ignored as prev is false by default ....   for(int j = 1; j<=m; j++) prev[j] = false;
    bool flag = true;

    for(int i = 1; i<=n; i++)
    {
        for(int ii=1; ii<=i;ii++)
        {
            if(s1[ii]!='*') flag = false;
            break;
        }
        curr[0] = flag;

        for(int j = 1; j<=m; j++)
        {
            if(s1[i-1] == s2[j-1] || s1[i-1] == '?') curr[j] = prev[j-1]; // if match move both index by 1 ( ? means 1 match )

            else if(s1[i-1] == '*') curr[j] = prev[j] | curr[j-1]; // either take * value as 0 or 1 (move i or j by 1)

            else curr[j] = false;
        }
        prev = curr;
    }
    return prev[m];
}

int main()
{
    string s1 = "ab*cd", s2 = "abdefcd";
    int n = s1.size();
    int m = s2.size();
    cout<<"recursion : "<<wildCard(s1, s2, n-1, m-1)<<"\n";

    //dp[n][m]   index from 0 to n-1
    vector<vector<int>> dp(n,vector<int>(m,-1));
    cout<<"memoization : "<<wildCardMem(s1, s2, n-1, m-1, dp)<<"\n";

    cout<<"tabulation : "<<wildCardTab(s1, s2)<<"\n";

    cout<<"space optimization : "<<wildCardSO(s1, s2)<<"\n";
    return 0;
}