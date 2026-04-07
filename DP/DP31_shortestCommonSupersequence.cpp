#include <bits/stdc++.h>
using namespace std;

string SCS(string &s1,string &s2)
{
    // LCS code
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
    // LCS code till now to create DP array

    string ans = "";
    int i = n, j = m; // set to DP last value
    while(i>0 && j>0)
    {
        if(s1[i-1] == s2[j-1]) // if element is same
        {
            ans += s1[i-1]; // add to ans once
            i--;            // movev diagonally
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) // if not match and up is greater
        {
            ans += s1[i-1];  // add to ans s1 element
            i--;             // move up
        }
        else                 // if not match and up is greater
        {
            ans += s2[j-1];  // add to ans s2 element
            j--;             // move left
        }
    }

    while(i>0) // if string s1 is left add remaining elements to ans
    {
        ans += s1[i-1];
        i--;
    }

    while(j>0) // if string s2 is left add remaining elements to ans
    {
        ans += s2[j-1];
        j--;
    }

    reverse(ans.begin(), ans.end()); // reverse the ans string as we were moving in DP array in reverse so it gave reverese ans

    return ans;
}

int main()
{
    string s1 = "brute", s2 = "groot";
    cout<<SCS(s1, s2);
    return 0;
}