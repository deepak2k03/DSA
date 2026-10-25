class Solution {
  public:
    
    int sumBetweenK1K2(vector<int>& arr, int k1, int k2) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int x : arr) {
            pq.push(x);
        }

        // Remove the first k1 smallest elements
        for (int i = 0; i < k1; i++) {
            pq.pop();
        }

        int sum = 0;

        // Add elements at positions k1+1 through k2-1
        for (int i = k1 + 1; i < k2; i++) {
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};