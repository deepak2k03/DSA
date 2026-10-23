class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int a[1001]={0};
        vector<int>ans;
        for(auto i:nums1) a[i]=1;
        for(auto i:nums2) {
            if(a[i]) {
                ans.push_back(i);
                a[i]=0;
            }
        }
        return ans;
    }
};