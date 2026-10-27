#include <bits/stdc++.h>
using namespace std;

bool isSorted(const vector<long long>& values, size_t index) {
    if (index + 1 >= values.size()) return true;
    return values[index] <= values[index + 1] && isSorted(values, index + 1);
}

int main() {
    int n;
    cin >> n;
    vector<long long> values(n);
    for (long long& value : values) cin >> value;
    cout << (isSorted(values, 0) ? "YES" : "NO");
}
