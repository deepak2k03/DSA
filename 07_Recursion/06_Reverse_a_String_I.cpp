#include <bits/stdc++.h>
using namespace std;

void reverseString(string& value, int left, int right) {
    if (left >= right) return;
    swap(value[left], value[right]);
    reverseString(value, left + 1, right - 1);
}

int main() {
    string value;
    cin >> value;
    reverseString(value, 0, static_cast<int>(value.size()) - 1);
    cout << value;
}
