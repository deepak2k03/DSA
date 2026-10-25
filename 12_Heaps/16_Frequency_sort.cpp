class Solution {
public:
    vector<int> frequencySort(vector<int>& arr) {
        unordered_map<int, int> freq;

        for (int x : arr) {
            freq[x]++;
        }

        // {frequency, element}
        // Frequency ascending; element descending for ties
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        for (auto &p : freq) {
            pq.push({p.second, -p.first});
        }

        vector<int> ans;

        while (!pq.empty()) {
            auto [f, negVal] = pq.top();
            pq.pop();

            int x = -negVal;

            for (int i = 0; i < f; i++) {
                ans.push_back(x);
            }
        }

        return ans;
    }
};