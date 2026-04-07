#include <bits/stdc++.h>
using namespace std;

//Question: either 1 tile vertical or 2 tiles horizontal

// similar to fibonacci

//Recursion
int tiles(int n)
{
    //base case
    if(n==0) return 0;
    if(n==1) return 1; // if n is 1 then only one tile vertically can be placed (1 way)
    if(n==2) return 2; // if n is 2 then 2 tiles vertically or 2 tiles horizontally can be placed (2 ways)

    return tiles(n-1)+tiles(n-2); // since it is number of ways so we add them
}

int main()
{
    cout<<tiles(3);
    return 0;
}