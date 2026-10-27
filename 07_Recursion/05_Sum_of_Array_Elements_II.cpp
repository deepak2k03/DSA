#include <bits/stdc++.h>
using namespace std;

long long sumOfArray(const vector<long long>& values, size_t index) {
    if (index == values.size()) return 0;
    return values[index] + sumOfArray(values, index + 1);
}

int main() {
    int n;
    cin >> n;
    vector<long long> values(n);
    for (long long& value : values) cin >> value;
    cout << sumOfArray(values, 0);
}
