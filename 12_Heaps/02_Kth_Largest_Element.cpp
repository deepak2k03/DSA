class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>maxh;
        int i=0;
        while(i<nums.size()){
            maxh.push(nums[i++]);
            if(maxh.size()>k) maxh.pop();
        }
        return maxh.top();
    }
};