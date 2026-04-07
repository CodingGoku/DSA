#include <bits/stdc++.h>
using namespace std;

// T: O(3^N) ... as it is creating 3 branches for `*`
// S: O(N) ... auxiliary stack space
bool isValid(string& str, int index, int cnt) {
    if(cnt < 0) return false;
    if(index == str.size()) {
        return cnt == 0; // if cnt = 0 return true, else false
    }

    if(str[index] == '(') return isValid(str, index+1, cnt+1);
    else if(str[index] == ')') return isValid(str, index+1, cnt-1);
    else { // if char is `*` , it can be `(` or `)` or ` `
        return isValid(str, index+1, cnt+1) || isValid(str, index+1, cnt-1) || isValid(str, index+1, cnt);
    }
}

// T: O(N^2)
// S: O(N^2)
bool isValidOP(string& str, int index, int cnt, vector<vector<int>>& dp) {
    if(cnt < 0) return false;
    if(index == str.size()) {
        return cnt == 0; // if cnt = 0 return true, else false
    }

    if(dp[index][cnt] != -1) return dp[index][cnt];

    if(str[index] == '(') return isValidOP(str, index+1, cnt+1, dp);
    else if(str[index] == ')') return isValidOP(str, index+1, cnt-1, dp);
    else { // if char is `*` , it can be `(` or `)` or ` `
        return dp[index][cnt] = isValidOP(str, index+1, cnt+1, dp) || isValidOP(str, index+1, cnt-1, dp) || isValidOP(str, index+1, cnt, dp);
    }
}

// T: O(N)
// S: O(1)
bool isValidSOP(string& str) {
    int n = str.size();
    int min = 0, max = 0;

    for(int i=0; i<n; i++) {
        if(str[i] == '(') {
            min++;
            max++;
        }
        else if(str[i] == ')') {
            min--;
            max--;
        }
        else {
            min--; // it can go at max 1 less by -1,0,+1
            max++; // it can go at max 1 more by -1,0,+1
        }

        if(min < 0) min = 0; // discard the -ve
        if(max < 0) return false; // if at any point it is -ve, it means not valid, example if first char is `)`
    }

    return min == 0;
}

int main()
{
    string str = "()*)*()";
    cout<<isValid(str, 0, 0)<<endl;

    int n = str.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
    cout<<isValidOP(str, 0, 0, dp)<<endl;

    cout<<isValidSOP(str)<<endl;

    return 0;
}