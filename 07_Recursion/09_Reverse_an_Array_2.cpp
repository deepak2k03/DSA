#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<long long>& values, int left, int right) {
    if (left >= right) return;
    swap(values[left], values[right]);
    reverseArray(values, left + 1, right - 1);
}

int main() {
    int n;
    cin >> n;
    vector<long long> values(n);
    for (long long& value : values) cin >> value;
    reverseArray(values, 0, n - 1);
    for (long long value : values) cout << value << ' ';
}
