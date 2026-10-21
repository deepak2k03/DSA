//only positives

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    map<long long, int>pre;
    long long sum=0;
    int maxLen=0;
    for(int i=0;i<a.size();i++){
        sum+=a[i];
        if(sum==k) maxLen=i+1;
        long long rem=sum-k;
        if(pre.find(rem)!=pre.end()){
            int len=i-pre[rem];
            maxLen=max(len, maxLen);
        }
        pre[sum]=i;
    }
    return maxLen;
}

//positives + zeros -> better

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    map<long long, int>pre;
    long long sum=0;
    int maxLen=0;
    for(int i=0;i<a.size();i++){
        sum+=a[i];
        if(sum==k) maxLen=i+1;
        long long rem=sum-k;
        if(pre.find(rem)!=pre.end()){
            int len=i-pre[rem];
            maxLen=max(len, maxLen);
        }
        if(pre.find(sum)==pre.end()) pre[sum]=i;
    }
    return maxLen;
}

//positives + zeros -> optimal (using two pointers)

int longestSubarrayWithSumK(vector<int> a, long long k) {
    int i=0, j=0;
    int maxLen=0;
    long long sum=0;
    while (j<a.size()) {
        sum+=a[j];
        while (sum>k && i<=j) {
            sum -= a[i];
            i++;
        }
        if(sum==k) maxLen=max(maxLen,j-i+1);
        j++;
    }
    return maxLen;
}


//positives + zeros + negatives -> optimal (jo positives + zeros ka better h)

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    map<long long, int>pre;
    long long sum=0;
    int maxLen=0;
    for(int i=0;i<a.size();i++){
        sum+=a[i];
        if(sum==k) maxLen=i+1;
        long long rem=sum-k;
        if(pre.find(rem)!=pre.end()){
            int len=i-pre[rem];
            maxLen=max(len, maxLen);
        }
        if(pre.find(sum)==pre.end()) pre[sum]=i;
    }
    return maxLen;
}

