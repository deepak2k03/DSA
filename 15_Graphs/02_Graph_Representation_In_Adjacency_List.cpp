#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 5; // Number of vertices
    vector<vector<int>> adj(n); // Adjacency list

    // Adding edges
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(4);
    adj[4].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[1].push_back(4);
    adj[4].push_back(1);

    adj[3].push_back(4);
    adj[4].push_back(3);

    // Print adjacency list
    for (int i = 0; i < n; ++i) {
        cout << "Node " << i << ": ";
        for (int neighbor : adj[i])
            cout << neighbor << " ";
        cout << "\n";
    }

    return 0;
}
