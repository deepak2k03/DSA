#include <bits/stdc++.h>
using namespace std;

long long sumOfDigits(long long number) {
    number = abs(number);
    if (number < 10) return number;
    return number % 10 + sumOfDigits(number / 10);
}

int main() {
    long long number;
    cin >> number;
    cout << sumOfDigits(number);
}
