class Solution {
public:
    string findOrder(vector<string>& words) {
        unordered_map<char, set<char>> adj;
        unordered_map<char, int> indegree;

        // Initialize all unique characters in the graph
        for (string word : words)
            for (char c : word)
                indegree[c] = 0;

        // Build the graph
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i], w2 = words[i + 1];
            int len = min(w1.length(), w2.length());
            bool foundDiff = false;
            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    if (adj[w1[j]].insert(w2[j]).second)
                        indegree[w2[j]]++;
                    foundDiff = true;
                    break;
                }
            }
            // Edge case: "abc", "ab" is invalid
            if (!foundDiff && w1.length() > w2.length()) return "";
        }

        // Topo Sort (Kahn’s Algorithm)
        queue<char> q;
        for (auto& it : indegree)
            if (it.second == 0) q.push(it.first);

        string result;
        while (!q.empty()) {
            char node = q.front(); q.pop();
            result += node;
            for (char nei : adj[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0)
                    q.push(nei);
            }
        }

        // If not all characters are in result, there's a cycle
        return result.length() == indegree.size() ? result : "";
    }
};
