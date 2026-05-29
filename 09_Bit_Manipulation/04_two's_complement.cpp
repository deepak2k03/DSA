//ans is one's complement+1

class Solution {
public:
    int twosComplement(int n) {
        if (n == 0) return 0;

        int mask = 0, temp = n;

        while (temp) {
            mask = (mask << 1) | 1;
            temp >>= 1;
        }

        int onesComplement = n ^ mask;
        return onesComplement + 1;
    }
};