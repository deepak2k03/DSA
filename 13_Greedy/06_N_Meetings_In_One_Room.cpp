struct Meeting {
    int start, end, pos;
};
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    
    static bool comparator(Meeting m1, Meeting m2) {
        if (m1.end == m2.end) return m1.pos < m2.pos;
        return m1.end < m2.end;
    }

    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n=start.size();
        vector<Meeting> meetings(n);
        
        for (int i = 0; i < n; i++) {
            meetings[i] = {start[i], end[i], i+1};
        }
        sort(meetings.begin(), meetings.end(), comparator);
    
        int count = 1;
        int lastEnd = meetings[0].end;
    
        for (int i = 1; i < n; i++) {
            if (meetings[i].start > lastEnd) {
                count++;
                lastEnd = meetings[i].end;
            }
        }
    
        return count;
        
    }
};
