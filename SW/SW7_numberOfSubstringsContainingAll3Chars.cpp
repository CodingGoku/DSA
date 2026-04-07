#include <bits/stdc++.h>
using namespace std;

// T: O(N^2)
// S: O(1)
int numberOfSubstringsContainingAll3Chars(string str) {
    int n = str.size();
    int arr[3] = {0}; // for 3 chars a,b,c
    int cnt = 0;

    for(int i=0; i<n; i++) {
        arr[0] = 0;
        arr[1] = 0;
        arr[2] = 0;
        for(int j=i; j<n; j++) {
            arr[str[j]-'a'] = 1;
            if(arr[0] + arr[1] + arr[2] == 3) cnt++;
        }
    }

    return cnt;
}

// T: O(N^2)
// S: O(1)
int numberOfSubstringsContainingAll3CharsOP(string str) {
    int n = str.size();
    int arr[3] = {0}; // for 3 chars a,b,c
    int cnt = 0;

    for(int i=0; i<n; i++) {
        arr[0] = 0;
        arr[1] = 0;
        arr[2] = 0;
        for(int j=i; j<n; j++) {
            arr[str[j]-'a'] = 1;
            if(arr[0] + arr[1] + arr[2] == 3) {
                cnt += (n-j);
                break;
            }
        }
    }

    return cnt;
}

// T: O(N)
// S: O(1)
int numberOfSubstringsContainingAll3CharsSOP(string str) {
    int n = str.size();
    int cnt = 0;
    int lastSeen[3] = {-1,-1,-1}; // set initial positions of a,b,c

    for(int i=0; i<n; i++) {
        lastSeen[str[i]-'a'] = i;
        if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
            cnt = cnt + (1 + min({lastSeen[0],lastSeen[1],lastSeen[2]})); // 1 + index of first element of window
        }
    }

    return cnt;
}

int main()
{
    string str = "bbacba";
    cout<<numberOfSubstringsContainingAll3Chars(str)<<endl;
    cout<<numberOfSubstringsContainingAll3CharsOP(str)<<endl;
    cout<<numberOfSubstringsContainingAll3CharsSOP(str)<<endl;
    return 0;
}