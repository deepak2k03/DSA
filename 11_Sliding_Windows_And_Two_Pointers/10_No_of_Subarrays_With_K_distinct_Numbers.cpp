class Solution {
public:
    int f(vector<int>&nums, int k){
        int l=0,r=0,c=0;
        map<int,int>m;
        while(r<nums.size()){
            m[nums[r]]++;
            while(m.size()>k){
                m[nums[l]]--;
                if(m[nums[l]]==0) m.erase(nums[l]);
                l++;
            }
            c=c+(r-l+1);
            r++;
        }
        return c;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums,k)-f(nums,k-1);
    }
};