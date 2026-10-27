#include <bits/stdc++.h>
using namespace std;

long long sumOfFirstN(long long n) {
    if (n <= 0) return 0;
    return n + sumOfFirstN(n - 1);
}

int main() {
    long long n;
    cin >> n;
    cout << sumOfFirstN(n);
}
