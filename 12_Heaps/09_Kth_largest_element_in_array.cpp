class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>minh;
        int i=0;
        while(i<nums.size()){
            minh.push(nums[i++]);
            if(minh.size()>k) minh.pop();
        }
        return minh.top();
    }
};