#include <bits/stdc++.h>
using namespace std;

// T: O(3N)
// S: O(2N)
int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> left(n), right(n);
    left[0] = 1; // first left does not have a neighbour on left, so it can have 1 candy
    right[n-1] = 1; // first right does not have a neighbour on right, so it can have 1 candy

    // left
    for(int i=1; i<n; i++) {
        if(ratings[i] > ratings[i-1]) {
            left[i] = left[i-1]+1;
        }
        else {
            left[i] = 1; // give atleast one candy
        }
    }

    // right
    for(int i=n-2; i>=0; i--) {
        if(ratings[i] > ratings[i+1]) {
            right[i] = right[i+1]+1;
        }
        else {
            right[i] = 1; // give atleast one candy
        }
    }

    // take max of left and right
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += max(left[i], right[i]);
    }

    return sum;
}

// T: O(N)
// S: O(1)
int candyOP(vector<int>& ratings) {
    int n = ratings.size();
    int sum = 1, i = 1; // leftmost has 1 candy

    while(i < n) {
        if(ratings[i] == ratings[i-1]) {
            sum += 1;
            i++;
            continue;
        }
        
        int peak = 1;
        while(i < n && ratings[i] > ratings[i-1]) {
            peak++;
            i++;
            sum += peak;
        }

        int down = 0;
        while(i < n && ratings[i] < ratings[i-1]) {
            down++;
            i++;
            sum += down;
        }

        down++; // extra left out peak part of decend
        if(down > peak) sum += (down-peak);
    }

    return sum;
}

int main()
{
    vector<int> ratings = {0,2,4,3,2,1,1,3,5,6,4,0,0};

    cout<<candy(ratings)<<endl;
    cout<<candyOP(ratings)<<endl;

    return 0;
}