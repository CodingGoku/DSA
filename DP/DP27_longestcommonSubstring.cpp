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

    int ans = 0;
    for(int ind1 = 1; ind1 <= n; ind1++)
    {
        for(int ind2 = 1; ind2 <= m; ind2++)
        {
             if(s1[ind1-1] == s2[ind2-1])
             {
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                ans = max(ans, dp[ind1][ind2]); // to take max value from the dp matrix
            }
            else dp[ind1][ind2] = 0; // ADD ELSE HERE as in recursion there was no need of else as the previous statement got returned
        }
    }
    return ans;
}

//space optimization
int lcsSO(string &s1,string &s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<int> prev (m+1,0), curr (m+1,0);
    //base case
    for(int i = 0; i<=n; i++) prev[0] = 0;
    // OMIT AS COLUMNS ARE NOT THERE NOW for(int j = 0; j<=n; j++) dp[0][j] = 0;

    int ans = 0;
    for(int ind1 = 1; ind1 <= n; ind1++)
    {
        for(int ind2 = 1; ind2 <= m; ind2++)
        {
             if(s1[ind1-1] == s2[ind2-1])
             {
                curr[ind2] = 1 + prev[ind2-1];
                ans = max(ans, curr[ind2]); // to take max value from the dp matrix
            }
            else curr[ind2] = 0; // ADD ELSE HERE as in recursion there was no need of else as the previous statement got returned
        }
        prev = curr;
    }
    return ans;
}

int main()
{
    string s1 = "abzd", s2 = "abcd";
    int n1 = s1.size();
    int n2 = s2.size();

    cout<<"tabulation : "<<lcsTab(s1, s2)<<"\n";

    cout<<"space optimization : "<<lcsSO(s1, s2)<<"\n";
    return 0;
}