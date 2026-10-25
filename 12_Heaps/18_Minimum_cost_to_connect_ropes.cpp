class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        int s=0;
        priority_queue<int, vector<int>, greater<int>>pq;
        for(auto i:arr) pq.push(i);
        while(pq.size()!=1){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            s+=x+y;
            pq.push(x+y);
        }
        return s;
    }
};