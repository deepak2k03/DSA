
class NumArray {
    vector<int> seg;
    int n;

    void build(int ind, int low, int high, vector<int>& nums) {
        if (low == high) {
            seg[ind] = nums[low];
            return;
        }

        int mid = low + (high - low) / 2;

        build(2 * ind + 1, low, mid, nums);
        build(2 * ind + 2, mid + 1, high, nums);

        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    void pointUpdate(int ind, int low, int high, int index, int val) {
        if (low == high) {
            seg[ind] = val;
            return;
        }

        int mid = low + (high - low) / 2;

        if (index <= mid)
            pointUpdate(2 * ind + 1, low, mid, index, val);
        else
            pointUpdate(2 * ind + 2, mid + 1, high, index, val);

        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    int rangeQuery(int ind, int low, int high, int left, int right) {
        // No overlap
        if (right < low || high < left)
            return 0;

        // Complete overlap
        if (left <= low && high <= right)
            return seg[ind];

        // Partial overlap
        int mid = low + (high - low) / 2;

        int lsum = rangeQuery(2 * ind + 1, low, mid, left, right);
        int rsum = rangeQuery(2 * ind + 2, mid + 1, high, left, right);

        return lsum + rsum;
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();

        if (n > 0) {
            seg.resize(4 * n, 0);
            build(0, 0, n - 1, nums);
        }
    }

    void update(int index, int val) {
        pointUpdate(0, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        return rangeQuery(0, 0, n - 1, left, right);
    }
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */