class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0, r=0, mx=0;
        map<int,int>m;
        while(r<fruits.size()){
            m[fruits[r]]++;
            if(m.size()>2){
                m[fruits[l]]--;
                if(m[fruits[l]]<=0) m.erase(fruits[l]);
                l++;
            }
            if(m.size()<=2) mx=max(mx,r-l+1);
            r++;
        }
        return mx;
    }
};