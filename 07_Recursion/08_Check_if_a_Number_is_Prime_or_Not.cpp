#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long number, long long divisor = 2) {
    if (number < 2) return false;
    if (divisor > number / divisor) return true;
    if (number % divisor == 0) return false;
    return isPrime(number, divisor + 1);
}

int main() {
    long long number;
    cin >> number;
    cout << (isPrime(number) ? "YES" : "NO");
}
