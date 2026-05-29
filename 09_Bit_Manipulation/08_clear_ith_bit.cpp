class Solution {
  public:
    void clear(int num, int i) {
        // your code here
        //0 based indexing of bits
        int clear = num & ~(1 << (i));
    }
};