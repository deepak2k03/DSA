
class Solution {
    class SGTree {
        vector<int> seg;
        int n;

    public:
        SGTree(int n) {
            this->n = n;
            seg.resize(4 * n + 1, 0);
        }

        void update(int ind, int low, int high, int i) {
            if (low == high) {
                seg[ind]++;
                return;
            }

            int mid = (low + high) / 2;

            if (i <= mid)
                update(2 * ind + 1, low, mid, i);
            else
                update(2 * ind + 2, mid + 1, high, i);

            seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
        }

        int query(int ind, int low, int high, int l, int r) {
            if (r < low || high < l)
                return 0;

            if (l <= low && high <= r)
                return seg[ind];

            int mid = (low + high) / 2;

            return query(2 * ind + 1, low, mid, l, r)
                 + query(2 * ind + 2, mid + 1, high, l, r);
        }

        void add(int index) {
            update(0, 0, n - 1, index);
        }

        int sum(int l, int r) {
            if (l > r) return 0;
            return query(0, 0, n - 1, l, r);
        }
    };

public:
    int inversionCount(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        vector<int> vals = arr;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        int m = vals.size();
        SGTree st(m);
        long long ans = 0;

        for (int x : arr) {
            int rank = lower_bound(vals.begin(), vals.end(), x)
                     - vals.begin();

            // Count previous elements strictly greater than x.
            ans += st.sum(rank + 1, m - 1);

            // Record the current element.
            st.add(rank);
        }

        return ans;
    }
};
