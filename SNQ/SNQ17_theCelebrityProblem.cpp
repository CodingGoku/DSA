#include <bits/stdc++.h>
using namespace std;

// T: 2N ... 2-pointer, check it top==down is celebrity
// S: 1
int celebrity(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    int top = 0, down = n-1;
    while(top < down) {
        // if top knows down,  top is not celebrity
        if(mat[top][down] == 1) top++;
        // if down knows top, down is not celebirty
        else if(mat[down][top] == 1) down--;
        else { 
            // both are 0, they dont know each other
            // but for celebrity someone has to know the other
            top++;
            down--;
        }
    }

    if(top > down) return -1; // no celebrity

    // check if current index, top == down is celebrity
    for(int i=0; i<n; i++) {
        if(i == top) continue; // diagonal is 0, one cannot know itself
        if((mat[top][i] == 0) && mat[i][top] == 1) NULL;// is celebrity
        else return -1;
    }

    return top;
}

int main()
{
    vector<vector<int>> mat = {
        {0,1,1,0},
        {0,0,0,0},
        {0,1,0,0},
        {1,1,0,0}
    };

    cout<<"Celebrity: "<<celebrity(mat);
}