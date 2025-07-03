class Solution {
public:
    int f(vector<int>arr, int goal){
        if(goal<0) return 0;
        int l=0,r=0,s=0,c=0;
        while(r<arr.size()){
            s+=arr[r];
            while(s>goal){
                s-=arr[l];
                l++;
            }
            c+=r-l+1;
            r++;
        }
        return c;
    }
    int numSubarraysWithSum(vector<int>& arr, int goal) {
        return f(arr,goal)-f(arr,goal-1);
    }
};