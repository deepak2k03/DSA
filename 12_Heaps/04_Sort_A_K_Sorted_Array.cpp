class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
        priority_queue<int,vector<int>,greater<int>>minh;
        int j=0;
        for(int i=0;i<arr.size();i++){
            minh.push(arr[i]);
            if(minh.size()>k){
                arr[j++]=minh.top();
                minh.pop();
            }
        }
        while(!minh.empty()){
            arr[j++]=minh.top();
            minh.pop();
        }
    }
};