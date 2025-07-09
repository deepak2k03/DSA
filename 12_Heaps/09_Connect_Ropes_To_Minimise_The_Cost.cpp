class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        int cost=0;
        priority_queue<int,vector<int>,greater<int>>minh;
        for(auto i:arr) minh.push(i);
        while(minh.size()>=2){
            int x=minh.top();
            minh.pop();
            int y=minh.top();
            minh.pop();
            cost+=(x+y);
            minh.push(x+y);
        }
        return cost;
    }
};