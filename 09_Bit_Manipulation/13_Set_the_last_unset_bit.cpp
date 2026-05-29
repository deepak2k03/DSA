class Solution {
  public:
    int setBit(int n) {
        // code here
        int pos=0;
        int ans=n;
        while((ans&1)!=0){
            ans=ans>>1;
            pos++;
        }
        return (1<<pos)|n; 
    }
};