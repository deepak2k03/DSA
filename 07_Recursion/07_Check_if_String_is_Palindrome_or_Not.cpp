#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string& value, int left, int right) {
    if (left >= right) return true;
    if (value[left] != value[right]) return false;
    return isPalindrome(value, left + 1, right - 1);
}

int main() {
    string value;
    cin >> value;
    cout << (isPalindrome(value, 0, static_cast<int>(value.size()) - 1) ? "YES" : "NO");
}
