class Solution {
  public:
  void solve(string &s, int start, vector<string>&v){
      if(start==s.size()-1){
          v.push_back(s);
          return;
      }
      unordered_set<char>map;
      for(int i=start;i<s.size();i++){
            if(map.find(s[i])==map.end()){
                map.insert(s[i]);
                swap(s[start],s[i]);
                solve(s,start+1,v);
                swap(s[start],s[i]);
            }
        }
        return;
  }
    vector<string> findPermutation(string &s) {
        // Code here there
        vector<string>v;
        solve(s,0,v);
        return v;
    }
};
