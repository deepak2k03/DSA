class Solution {
public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans;
        queue<int> q;  // stores indices of negative elements

        int left = 0;
        int right = 0;

        while (right < n) {

            // Add negative element to queue
            if (arr[right] < 0)
                q.push(right);

            // Window size = k
            if (right - left + 1 == k) {
                
                // First negative in current window
                if (!q.empty())
                    ans.push_back(arr[q.front()]);
                else
                    ans.push_back(0);
                
                if(arr[left]<0 && !q.empty()) q.pop();
                
                // Slide window
                left++;
            }

            right++;
        }

        return ans;
    }
};