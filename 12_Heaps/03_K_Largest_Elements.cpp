class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        priority_queue<int,vector<int>,greater<int>>maxh;
        int i=0;
        while(i<arr.size()){
            maxh.push(arr[i++]);
            if(maxh.size()>k) maxh.pop();
        }
        vector<int>v;
        while(!maxh.empty()){
            v.push_back(maxh.top());
            maxh.pop();
        }
        reverse(begin(v),end(v));
        return v;
    }
};