//brute
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        int c=0;
        for(auto i:g){
            if(lower_bound(s.begin(),s.end(),i)!=s.end()){
                c++;
                s.erase(lower_bound(s.begin(),s.end(),i));
            }
        }
        return c;
    }
};

//optimal
class Solution {
  public:
    int maxChildren(vector<int> &greed, vector<int> &cookie) {
        // code here
        sort(begin(greed), end(greed));
        sort(begin(cookie), end(cookie));
        int ptr1=0,ptr2=0;
        while(ptr1<greed.size()){
            if(greed[ptr1]<=cookie[ptr2]){
                ptr1++;
            }
            ptr2++;
            if(ptr2>=cookie.size()) break;
        }
        return ptr1;
    }
};