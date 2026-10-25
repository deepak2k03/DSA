class Solution {
public:
    vector<int> kSmallest(vector<int>& arr, int k) {
        priority_queue<int> pq;
        vector<int> ans;

        int i = 0;
        while (i < arr.size()) {
            pq.push(arr[i++]);

            if (pq.size() > k)
                pq.pop();
        }

        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};