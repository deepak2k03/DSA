class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int bi=0;bi<=31;bi++){
            int c=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]&(1<<bi)){
                    c++;
                }
            }
            if(c%3==1) ans=ans|(1<<bi);
        }
        return ans;
    }
};

