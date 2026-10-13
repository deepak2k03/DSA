class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();

        vector<pair<int, int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }

        sort(jobs.rbegin(), jobs.rend());

        int maxDeadline = *max_element(deadline.begin(), deadline.end());
        vector<int> slots(maxDeadline + 1, -1);

        int count = 0, totalProfit = 0;

        for (auto &job : jobs) {
            int p = job.first;
            int d = job.second;

            for (int t = min(d, maxDeadline); t >= 1; t--) {
                if (slots[t] == -1) {
                    slots[t] = 1;
                    count++;
                    totalProfit += p;
                    break;
                }
            }
        }

        return {count, totalProfit};
    }
};

// can be optimized using DSU