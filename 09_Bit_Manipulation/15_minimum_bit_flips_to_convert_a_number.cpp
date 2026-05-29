class Solution {
public:
    int minBitFlips(int start, int goal) {
        int mx=max(start,goal);
        int ans=0;
        while(mx){
            if((start&1)!=(goal&1)) ans++;
            start>>=1;
            goal>>=1;
            mx>>=1;
        }
        return ans;
    }
};