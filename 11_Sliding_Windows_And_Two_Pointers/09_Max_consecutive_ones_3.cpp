//optimal 
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,z=0,mx=0;
        while(r<nums.size()){
            if(nums[r]==0) z++;
            if(z>k){
                if(nums[l]==0) z--;
                l++;
            }
            if(z<=k) mx=max(r-l+1,mx);
            r++;
        }
        return mx;
    }
};


