#include <bits/stdc++.h>
using namespace std;

// T : N x wordLength x 26 x logN
// S : N
int wordLadder(vector<string>& wordList, string startWord, string targetWord) {
    int n = startWord.size();
    if(n != targetWord.size()) return -1; // not possible

    queue<pair<string, int>> q; // word, step
    q.push({startWord, 1}); // initially start with startWord with step 1
    unordered_set<string> st(wordList.begin(), wordList.end());

    while(!q.empty()) {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if(word == targetWord) return steps;

        for(int i=0; i<n; i++) {
            char original = word[i];
            for(char ch='a'; ch<='z'; ch++) {
                word[i] = ch; // replace ith char
                if(st.find(word) != st.end()) {
                    q.push({word, steps+1});
                    st.erase(word); // we dont want to find this word again, which we have already visited
                }
            }
            word[i] = original; // so that we replace only 1 char at a time
        }
    }
    return 0;
}

int main()
{
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    string startWord = "hit";
    string targetWord = "cog";
    cout<<"Steps : "<<wordLadder(wordList, startWord, targetWord);
    return 0;
}