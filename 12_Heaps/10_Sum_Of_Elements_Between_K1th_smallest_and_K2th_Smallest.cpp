class Solution {
  public:
    int kthSmallest(long long a[], long long n, long long k){
        priority_queue<long long>maxh;
        for(int i=0;i<n;i++){
            maxh.push(a[i]);
            if(maxh.size()>k) maxh.pop();
        }
        return maxh.top();
    }
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        // Your code goes here
        int k1=kthSmallest(A,N,K1);
        int k2=kthSmallest(A,N,K2);
        long long s=0;
        for(int i=0;i<N;i++) if(A[i]>k1 && A[i]<k2) s+=A[i];
        return s;
    }
};