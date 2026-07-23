#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
            // Outer loop for rows
        for (int i = 0; i < 2 * n - 1; i++) {
            // Inner loop for columns
            for (int j = 0; j < 2 * n - 1; j++) {
                // Calculate distance from top
                int top = i;
                // Calculate distance from left
                int left = j;
                // Calculate distance from bottom
                int bottom = (2 * n - 2) - i;
                // Calculate distance from right
                int right = (2 * n - 2) - j;

                // Take the minimum of all four distances
                int minDist = min(min(top, bottom), min(left, right));

                // Print number (starts with n at border, decreases inside)
                cout << (n - minDist) << " ";
            }
            // Move to the next row
            cout << endl;
        }
    cout<<endl;
    return 0;
}