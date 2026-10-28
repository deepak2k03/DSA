
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define print(x) cout << x << '\n'

class SGTree {
    vector<int> seg;

public:
    SGTree(int n) {
        seg.resize(4 * n + 1, LLONG_MAX);
    }

    void build(int ind, int low, int high, vector<int>& a) {
        if (low == high) {
            seg[ind] = a[low];
            return;
        }

        int mid = (low + high) / 2;

        build(2 * ind + 1, low, mid, a);
        build(2 * ind + 2, mid + 1, high, a);

        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int query(int ind, int low, int high, int l, int r) {
        // No overlap
        if (r < low || high < l) return LLONG_MAX;

        // Complete overlap
        if (l <= low && high <= r) return seg[ind];

        // Partial overlap
        int mid = (low + high) / 2;

        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);

        return min(left, right);
    }
};

int32_t main() {
    fast

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    SGTree st(n);
    st.build(0, 0, n - 1, a);

    while (q--) {
        int a, b;
        cin >> a >> b;

        // Convert 1-based query to 0-based indices
        cout << st.query(0, 0, n - 1, a - 1, b - 1) << '\n';
    }

    return 0;
}
