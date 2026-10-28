
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define print(x) cout << x << '\n'

class SGTree {
    vector<int> seg;

public:
    SGTree(int n) {
        seg.resize(4 * n + 1, 0);
    }

    void build(int ind, int low, int high, vector<int>& a) {
        if (low == high) {
            seg[ind] = a[low];
            return;
        }

        int mid = (low + high) / 2;

        build(2 * ind + 1, low, mid, a);
        build(2 * ind + 2, mid + 1, high, a);

        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    int query(int ind, int low, int high, int l, int r) {
        // No overlap
        if (r < low || high < l) return 0;

        // Complete overlap
        if (l <= low && high <= r) return seg[ind];

        // Partial overlap
        int mid = (low + high) / 2;

        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);

        return left + right;
    }

    void update(int ind, int low, int high, int i, int val) {
        if (low == high) {
            seg[ind] = val;
            return;
        }

        int mid = (low + high) / 2;

        if (i <= mid)
            update(2 * ind + 1, low, mid, i, val);
        else
            update(2 * ind + 2, mid + 1, high, i, val);

        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
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
        int type;
        cin >> type;

        if (type == 1) {
            int k, u;
            cin >> k >> u;

            // 1-based to 0-based index
            st.update(0, 0, n - 1, k - 1, u);
        } 
        else {
            int a, b;
            cin >> a >> b;

            // Inclusive range [a, b]
            cout << st.query(0, 0, n - 1, a - 1, b - 1) << '\n';
        }
    }

    return 0;
}
