class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsm=0,rsm=0,mxsm=0;
        for(int i=0;i<k;i++) lsm+=cardPoints[i];
        mxsm=lsm;
        int ridx=cardPoints.size()-1;
        for(int i=k-1;i>=0;i--){
            lsm-=cardPoints[i];
            rsm+=cardPoints[ridx];
            mxsm=max(mxsm,lsm+rsm);
            ridx--;
        }
        return mxsm;
    }
};