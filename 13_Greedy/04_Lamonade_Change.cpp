class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        int five=0;
        int ten=0;
        for(auto i:arr){
            if(i==5) five++;
            else if(i==10){
                if(five){
                    ten++;
                    five--;
                }
                else return false;
            }
            else{
                if(ten && five){
                    ten--;
                    five--;
                }
                else if(five>=3) five-=3;
                else return false;
            }
            
        }
        return true;
    }
};