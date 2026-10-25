class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        int n = arr.size();
        int i = 0;

        // Insert the first k+1 elements
        for (; i < min(n, k + 1); i++) {
            pq.push(arr[i]);
        }

        int idx = 0;

        // Extract minimum and insert the next element
        while (i < n) {
            arr[idx++] = pq.top();
            pq.pop();

            pq.push(arr[i++]);
        }

        // Empty the remaining heap
        while (!pq.empty()) {
            arr[idx++] = pq.top();
            pq.pop();
        }
    }
};