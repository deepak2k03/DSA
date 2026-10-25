class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // code here
        priority_queue<int, vector<int>, greater<int>>pq;
        vector<int>ans;
        int i=0;
        while(i<arr.size()){
            pq.push(arr[i++]);
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};