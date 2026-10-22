#include<bits/stdc++.h>
using namespace std;
int getLengthofLongestSubstring(int k, string s)
{
   // Write your code here.
   int l=0,r=0,mx=0;
   map<char, int>m;
   while(r<s.size()){
      m[s[r]]++;
      if(m.size()>k){
         m[s[l]]--;
         if(m[s[l]]<=0) m.erase(s[l]);
         l++;
      }
      if(m.size()<=k) mx=max(mx, r-l+1);
      r++;
   }
   return mx;
}
