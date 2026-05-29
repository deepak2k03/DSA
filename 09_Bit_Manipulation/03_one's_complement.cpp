// create mask of same 1 bits and then ans is mask^n
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int mask=0, temp=n;
        while(temp){
            mask=((mask<<1) | 1);
            temp=temp>>1;
        }
        return n^mask;
    }
};