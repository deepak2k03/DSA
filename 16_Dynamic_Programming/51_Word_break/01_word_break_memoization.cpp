class Solution {
  public:
    bool f(int i, string& s, unordered_set<string>& words,
           vector<int>& dp) {
        if (i == static_cast<int>(s.size())) return true;
        if (dp[i] != -1) return dp[i];

        string current;
        for (int j = i; j < static_cast<int>(s.size()); j++) {
            current += s[j];
            if (words.count(current) && f(j + 1, s, words, dp)) {
                return (dp[i] = true);
            }
        }
        return (dp[i] = false);
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);
        return f(0, s, words, dp);
    }
};
