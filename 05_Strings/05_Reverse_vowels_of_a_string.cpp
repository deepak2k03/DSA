class Solution
{
public:
    string reverseVowels(string s)
    {
        vector<int> vowels;
        string vowelss = "aeiouAEIOU";
        for (int i = 0; i < s.size(); i++)
            if (vowelss.find(s[i]) != string::npos)
                vowels.push_back(i);
        for (int i = 0; i < vowels.size() / 2; i++)
            swap(s[vowels[i]], s[vowels[vowels.size() - i - 1]]);
        return s;
    }
};