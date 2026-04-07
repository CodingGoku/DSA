#include <bits/stdc++.h>
using namespace std;

// T : O(N)
// S : O(1)
int buySell(vector<int> &price)
{
    int mini = price[0]; // mini is the buying price

    int profit = 0;
    for(int i = 0; i<price.size(); i++) // we can even buy and sell on same day
    {
        int cost = price[i] - mini; // cost is the new profit
        profit = max(profit, cost); // updating profit with new profit

        mini = min(mini, price[i]); // updating minimum buying price before going to
                                    // next selling price
    }
    return profit;
}

// What is Dynamic Programming here ?
// DP is remembering the past, and here remembering the minimum

int main()
{
    vector<int> price {7,1,5,3,6,4};
    cout<<"max profit is : "<<buySell(price);
    return 0;
}