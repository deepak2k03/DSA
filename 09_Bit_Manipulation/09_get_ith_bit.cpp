class Solution {
  public:
    int bitManipulation(int num, int i) {
        // your code here
        int get = (num >> (i - 1)) & 1;
        return get;
    }
};