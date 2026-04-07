#include <bits/stdc++.h>
using namespace std;

// Recursion
// T : O(3^n x 3^m)
// S : O(n + m)
int editDist(string s1, string s2, int i, int j)
{
    //base case
    if(i < 0) return j+1; // string s1 finishes, minimum steps to convert to s2 is (inserting) remaining letters of s2 i.e. j+1
    if(j < 0) return i+1; // string s2 finishes, minimum steps to convert to s2 is (deleting) remaining letters of s1 i.e. i+1
    if(s1[i] == s2[j]) return editDist(s1, s2, i-1, j-1);
    //else
    int deletee = 1 + editDist(s1, s2, i-1, j);
    int insert = 1 + editDist(s1, s2, i, j-1);
    int replace = 1 + editDist(s1, s2, i-1, j-1);

    return min(deletee,min(insert, replace));
}

// Memoization
// T : O(N x M)
// S : O(N x M) + O(N + M) auxiliary stack space
int editDistMem(string s1, string s2, int i, int j, vector<vector<int>> dp)
{
    //base case
    if(i < 0) return j+1; // string s1 finishes, minimum steps to convert to s2 is (inserting) remaining letters of s2 i.e. j+1
    if(j < 0) return i+1; // string s2 finishes, minimum steps to convert to s2 is (deleting) remaining letters of s1 i.e. i+1
    
    if(dp[i][j] != -1) return dp[i][j];
    
    if(s1[i] == s2[j]) return editDistMem(s1, s2, i-1, j-1, dp);

    //else
    int deletee = 1 + editDistMem(s1, s2, i-1, j, dp);
    int insert = 1 + editDistMem(s1, s2, i, j-1, dp);
    int replace = 1 + editDistMem(s1, s2, i-1, j-1, dp);

    return dp[i][j] = min(deletee,min(insert, replace));
}

// Tabulation
// T : O(N x M)
// S : O(N x M)
int editDistTab(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp (n+1, vector<int>(m+1,0)); // 1-based indexing

    //base case
    for(int j = 0; j <= m; j++) dp[0][j] = j; // j = j -1 for dp value instead of j + 1 it is now just j
    for(int i = 1; i <= n; i++) dp[i][0] = i; // i STARTS FROM 1 AS IN PREVIOUS LINE WE HAVE DONE i = 0   ... i = i - 1 for dp value 

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s1[i-1] == s2[j-1]) dp[i][j] =  dp[i-1][j-1]; // i = i-1   &   j = j - 1   in if statement

            //else
            else
            {
                int deletee = 1 + dp[i-1][j];
                int insert = 1 + dp[i][j-1];
                int replace = 1 + dp[i-1][j-1];
                dp[i][j] = min(deletee,min(insert, replace));
            }
        }
    }
    return dp[n][m];
}

// Space Optimization
// T : O(N x M)
// S : O(N)
int editDistSO(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<int> prev (m+1,0), curr (m+1,0); // no. of columns is the size of the rows

    //base case
    // OMIT as we are not dealing with columns   ...   for(int j = 0; j <= m; j++) dp[0][j] = j;
    for(int j = 0; j <= m; j++) prev[j] = j;

    for(int i = 1; i <= n; i++)
    {
        curr[0] = i; // FOR THE OTHER BASE CASE
        for(int j = 1; j <= m; j++)
        {
            if(s1[i-1] == s2[j-1]) curr[j] =  prev[j-1]; // i = i-1   &   j = j - 1   in if statement

            //else
            else
            {
                int deletee = 1 + prev[j];
                int insert = 1 + curr[j-1];
                int replace = 1 + prev[j-1];
                curr[j] = min(deletee,min(insert, replace));
            }
        }
        prev = curr; // ek for loop ke baad ... or just before last for loop
    }
    return prev[m];
}


int main()
{
    string s1 = "horse", s2 = "ros";
    int n = s1.size(); // index i
    int m = s2.size(); // index j
    
    cout<<"recursion : "<<editDist(s1, s2, n-1, m-1)<<"\n";

    // dp[n][m]    index from 0 to n-1
    vector<vector<int>> dp(n, vector<int>(m,-1));
    cout<<"memoization : "<<editDistMem(s1, s2, n-1, m-1, dp)<<"\n";

    cout<<"tabulation : "<<editDistTab(s1, s2)<<"\n";

    cout<<"space optimization : "<<editDistSO(s1, s2)<<"\n";
    return 0;
}