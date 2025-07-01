//this dp sol gives tle
// class Solution {
// public:
//     int f(int idx, int jumps, vector<int>& nums){
//         int n = nums.size();
//         if(idx >= n - 1) return jumps;
//         int mini = INT_MAX;
//         for(int i = 1; i <= nums[idx]; i++) {
//             mini = min(mini, f(idx + i, jumps + 1, nums));
//         }
//         return mini;
//     }
//     int jump(vector<int>& nums) {
//         return f(0, 0, nums);
//     }
// };

class Solution {
public:
    
    int jump(vector<int>& nums) {
        int l=0,r=0,jumps=0,n=nums.size();
        while(r<n-1){
            int farthest=0;
            for(int i=l;i<=r;i++) farthest=max(farthest,i+nums[i]);
            l=r+1;
            r=farthest;
            jumps++;
        }
        return jumps;
    }
};
