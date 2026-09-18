class Solution {
public:

    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        int n = arr.size();

        // Deque stores indices of useful elements.
        // The elements are maintained in decreasing order of value.
        // So, the front always contains the index of the maximum element
        // of the current window.
        deque<int> dq;

        vector<int> ans;

        for (int i = 0; i < n; i++) {

            // 1. Remove indices that are outside the current window.
            //
            // Current window: [i-k+1 ... i]
            // Any index <= i-k is no longer inside the window.
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // 2. Remove elements from the back that are smaller than
            // or equal to arr[i].
            //
            // They can never become the maximum while arr[i] is present
            // in the window, so we don't need to keep them.
            while (!dq.empty() && arr[i] >= arr[dq.back()]) {
                dq.pop_back();
            }

            // 3. Add the current element's index.
            dq.push_back(i);

            // 4. A complete window of size k is formed only when
            // i >= k-1.
            //
            // Example: k = 3
            // First complete window is at indices [0, 1, 2],
            // so we start storing answers when i = 2 (k-1).
            if (i >= k - 1) {
                // The front of deque contains the index
                // of the maximum element in the current window.
                ans.push_back(arr[dq.front()]);
            }
        }

        return ans;
    }
};


