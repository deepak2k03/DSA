class Solution {
  public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        int n = s.size();

        vector<tuple<int, int, int>> meetings;

        for (int i = 0; i < n; i++) {
            meetings.push_back({f[i], i + 1, s[i]});
        }

        sort(meetings.begin(), meetings.end());

        vector<int> ans;
        int lastFinish = -1;

        for (auto &[finish, index, start] : meetings) {
            if (start > lastFinish) {
                ans.push_back(index);
                lastFinish = finish;
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};