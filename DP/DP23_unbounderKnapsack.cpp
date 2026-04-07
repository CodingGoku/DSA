#include <bits/stdc++.h>
using namespace std;

//Recursion
// T : O(>> 2^N) exponential
// S : O(>> N) ... O(W)
int knapsack(int ind, int W, vector<int> &wt, vector<int> &val)
{
    //base case
    if(ind == 0)
    {
        return (int) (W/wt[0])*val[0];
    }

    int not_take = 0 + knapsack(ind-1,W,wt,val); // if not taken anything it should return 0
    int take = INT_MIN; // if not taken then it should not be considered in max function
    if(wt[ind] <= W) take = val[ind] + knapsack(ind,W-wt[ind],wt,val);

    return max(take,not_take);
}

int main()
{
    // bag size is 10
    int W = 10;
    vector<int> wt {2,4,6};
    vector<int> val {5,11,13};

    int n = wt.size();

    cout<<"recursion : "<<knapsack(n-1,10,wt,val)<<"\n";
    return 0;
}