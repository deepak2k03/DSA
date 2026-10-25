class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> pq;
        int i=0;
        while(i<arr.size()){
            pq.push(arr[i++]);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};