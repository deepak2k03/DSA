class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> m;
        map<string, char> rev;
        vector<string> v;

        stringstream ss(s);
        string temp;

        while (ss >> temp)
            v.push_back(temp);

        if (pattern.size() != v.size())
            return false;

        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string word = v[i];

            if (m.count(c) && m[c] != word)
                return false;

            if (rev.count(word) && rev[word] != c)
                return false;

            m[c] = word;
            rev[word] = c;
        }

        return true;
    }
};