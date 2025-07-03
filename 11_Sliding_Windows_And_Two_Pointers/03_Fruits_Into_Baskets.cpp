class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        map<int,int>m;
        int l=0,r=0;
        int maxLen=0;
        while(r<arr.size()){
            m[arr[r]]++;
            if(m.size()>2){
                m[arr[l]]--;
                if(m[arr[l]]==0) m.erase(arr[l]);
                l++;
            }
            if(m.size()<=2) maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};