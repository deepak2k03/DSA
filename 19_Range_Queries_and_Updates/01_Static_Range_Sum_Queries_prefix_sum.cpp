
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int32_t main() {
    fast

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    vector<int> pref(n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }

    while (q--) {
        int a, b;
        cin >> a >> b;

        cout<<(pref[b] - pref[a - 1])<<endl;
    }

    return 0;
}
