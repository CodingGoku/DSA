#include <bits/stdc++.h>
using namespace std;

int buySellSO(vector<int> price, int ind, int buy, int k)
{
    int n = price.size();
    vector<vector<int>> after (2,vector<int>(k+1,0)), curr (2,vector<int>(k+1,0));

    for(int ind = n-1; ind>=0; ind--)
    {
        for(int buy = 0; buy<=1; buy++)
        {
            for(int cap = 1; cap<=k; cap++)
            {

                if(buy)
                {
                    curr[buy][cap] = max(-price[ind] + after[0][cap], 0 + after[1][cap]);
                }
                else
                {
                    curr[buy][cap] = max(price[ind] + after[1][cap-1], 0 + after[0][cap]);
                }
            }
            after = curr; // swap the 2 arrays
        }
    }
    return after[1][k];
}

int main()
{
    vector<int> price {3,3,5,0,0,3,1,4};
    int n = price.size();
    int k = 3;
    cout<<"space optimization : "<<buySellSO(price, 0, 1, k)<<"\n";
    return 0;
}