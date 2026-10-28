
#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);

struct Node {
    int open, close, matched;

    Node(int o = 0, int c = 0, int m = 0) {
        open = o;
        close = c;
        matched = m;
    }
};

class SGTree {
    vector<Node> seg;
    string s;

    Node merge(Node left, Node right) {
        int pairs = min(left.open, right.close);

        Node res;
        res.matched = left.matched + right.matched + 2 * pairs;
        res.open = left.open + right.open - pairs;
        res.close = left.close + right.close - pairs;

        return res;
    }

public:
    SGTree(string& str) {
        s = str;
        int n = s.size();
        seg.resize(4 * n);
        build(0, 0, n - 1);
    }

    void build(int ind, int low, int high) {
        if (low == high) {
            if (s[low] == '(')
                seg[ind] = Node(1, 0, 0);
            else
                seg[ind] = Node(0, 1, 0);
            return;
        }

        int mid = (low + high) / 2;

        build(2 * ind + 1, low, mid);
        build(2 * ind + 2, mid + 1, high);

        seg[ind] = merge(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    Node query(int ind, int low, int high, int l, int r) {
        // No overlap
        if (high < l || r < low)
            return Node();

        // Complete overlap
        if (l <= low && high <= r)
            return seg[ind];

        // Partial overlap
        int mid = (low + high) / 2;

        Node left = query(2 * ind + 1, low, mid, l, r);
        Node right = query(2 * ind + 2, mid + 1, high, l, r);

        return merge(left, right);
    }

    int answer(int l, int r) {
        return query(0, 0, (int)s.size() - 1, l, r).matched;
    }
};

int main() {
    fast

    string s;
    cin >> s;

    int m;
    cin >> m;

    SGTree st(s);

    while (m--) {
        int l, r;
        cin >> l >> r;

        cout << st.answer(l - 1, r - 1) << '\n';
    }

    return 0;
}
