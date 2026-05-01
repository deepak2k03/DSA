#include <bits/stdc++.h>
using namespace std;

#define MAXN 90000000

bitset<MAXN + 1> isPrime; //using array/vector takes more space
vector<int> primes;

int main() {
    

    // Sieve
    isPrime.set(); // mark all as true
    isPrime[0] = isPrime[1] = 0;

    for (int i = 2; i * i <= MAXN; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAXN; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    // Store primes
    for (int i = 2; i <= MAXN; i++) {
        if (isPrime[i]) primes.push_back(i);
    }

    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        cout << primes[k - 1] << '\n';
    }

    return 0;
}