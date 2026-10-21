//using map
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        unordered_map<char, int> lastSeen;

        int left = 0;
        int maxLen = 0;

        // Move right across the string.
        for (int right = 0; right < s.size(); right++) {

            // Move left only when the
            // duplicate is inside the window.
            if ( lastSeen.count(s[right]) && lastSeen[s[right]] >= left) {
                left = lastSeen[s[right]] + 1;
            }

            lastSeen[s[right]] = right;

            maxLen = max(maxLen,right - left + 1);
        }

        return maxLen;
    }
};


//using set
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        set<char>st;
        int mx=0;
        int i=0,j=0;
        while(j<s.size()){
            if(st.find(s[j])==st.end()) st.insert(s[j]);
            else{
                while (st.find(s[j]) != st.end()) {
                    st.erase(s[i]);
                    i++;
                }
                st.insert(s[j]);
            }
            mx = max(mx,j-i+1);
            j++;
        }
        return mx;
    }
};
