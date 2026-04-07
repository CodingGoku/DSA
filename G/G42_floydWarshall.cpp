#include <bits/stdc++.h>
using namespace std;

// T : V x V x V
// S : V x V ... for given matrix
void floydWarshall(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                // question states if weight is -1, it means node is unreachable, so we set it to 1e9 making sure not to reach it
                if(matrix[i][j] == -1) matrix[i][j] = 1e9;

                if(i == j) matrix[i][j] = 0; // diagonal or distance to itself is always 0, even if matrix has some value for it
            }
        }

        // k is the node via which we go from i to j
        for(int k=0; k<n; k++) {
            for(int j=0; j<n; j++) {
                for(int i=0; i<n; i++) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }

        // to detect negative cycle ... distance from node to itself cannot be < 0
        for(int i=0; i<n; i++) {
            if(matrix[i][i] < 0) cout<<"It has a negative cycle";
        }

        // reset 1e9 to -1 as that was given earlier for nodes we cannot visit
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == 1e9) matrix[i][j] = -1;
            }
        }

        // print matrix
        for(auto i : matrix) {
            cout<<"[";
            for(auto j : i) cout<<j<<" ";
            cout<<"]\n";
        }
}

int main()
{
    // this matrix contains only weights from node i to node j
    vector<vector<int>> matrix = {{0,2,-1,-1},
                                  {1,0,3,-1},
                                  {-1,-1,0,-1},
                                  {3,5,4,0}};

    floydWarshall(matrix);
    return 0;
}