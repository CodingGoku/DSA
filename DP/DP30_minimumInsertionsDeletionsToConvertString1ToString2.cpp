#include <bits/stdc++.h>
using namespace std;

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
    // (n + m) - 2 x (LCS)
    return n+m-2*dp[n][m];
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
    // (n + m) - 2 x (LCS)
    return n+m-2*prev[m];
}

int main()
{
    string str1 = "abcd";
    string str2 = "anc";



    cout<<"tabulation : "<<lcsTab(str1, str2)<<"\n";

    cout<<"space optimization : "<<lcsSO(str1, str2)<<"\n";
    return 0;
}