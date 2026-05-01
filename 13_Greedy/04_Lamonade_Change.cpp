class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int d5=0,d10=0;
        for(auto i:bills){
            if(i==5) d5++;
            else if(i==10){
                if(d5<=0) return false;
                else{
                    d10++;
                    d5--;
                }
            }
            else if(d5>0 & d10>0){
                d5--;
                d10--;
            }
            else if(d5>=3) d5-=3;
            else return false;
        }
        return true; 
    }
};