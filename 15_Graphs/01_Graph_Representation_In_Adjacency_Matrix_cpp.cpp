#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 5; // Number of vertices
    vector<vector<int>> adj(n, vector<int>(n, 0));

    // Example edges: 0-1, 0-4, 1-2, 1-3, 1-4, 3-4
    adj[0][1] = 1;
    adj[1][0] = 1;

    adj[0][4] = 1;
    adj[4][0] = 1;

    adj[1][2] = 1;
    adj[2][1] = 1;

    adj[1][3] = 1;
    adj[3][1] = 1;

    adj[1][4] = 1;
    adj[4][1] = 1;

    adj[3][4] = 1;
    adj[4][3] = 1;

    // Printing the adjacency matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << adj[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
_______________________________________________________________________________________________________________________________________________________________________________

adj[u][v] = 1;  // Only one direction
_______________________________________________________________________________________________________________________________________________________________________________
adj[u][v] = weight;
// if undirected
adj[v][u] = weight;

