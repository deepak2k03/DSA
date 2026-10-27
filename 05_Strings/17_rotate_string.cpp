class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.size()>s.size()) return false;
        return (s.size()<=goal.size()) && ((s+s).find(goal)!=string::npos);
    }
};