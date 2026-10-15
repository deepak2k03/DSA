class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        sort(begin(arr),end(arr));
        sort(begin(dep),end(dep));
        int c=0, mx=0;
        int i=0,j=0;
        while(i<arr.size() && j<dep.size()){
            if(arr[i]<=dep[j]){
                c++;
                i++;
            }
            else{
                c--;
                j++;
            }
            mx=max(mx,c);
        }
        return mx;
    }
};
