#include <bits/stdc++.h>
using namespace std;

//from previous question
// Tabulation
void lcsTab(string &s1,string &s2)
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
    // HERE WE ARE DOING THE NEXT PART FOR THIS QUESTION

    // lets print the dp
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }

    int len = dp[n][m];
    string ans = "";
    for(int i=0; i<len; i++) ans += '$'; // create a dummy string of $ values of same size of answer

    int index = len - 1;
    int i = n, j = m;
    while(i>0 && j>0)
    {
        if(s1[i-1] == s2[j-1]) // if both are element matches then add to the answer that element 
        {
            ans[index] = s1[i-1]; // and decrement i and j and index
            index--;
            i--, j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) // if doesn't match then take max(dp[ind1-1][ind2],dp[ind1][ind2-1])
        {
            i--; // if dp[i-1][j] is greater then decrement i 
        }
        else j--; // else when dp[i][j-1] is greater then decrement j
    }
    cout<<"\n"<<ans;
}



int main()
{
    string s1 = "adcbc", s2 = "dcadb";
    int n1 = s1.size();
    int n2 = s2.size();

    cout<<"tabulation : \n\n";lcsTab(s1, s2);cout<<"\n";
    return 0;
}