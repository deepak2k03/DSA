void printPrimeFactorization(int n) {
    // code here
    vector<int>ans;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            ans.push_back(i);
            n/=i;
        }
    }
    if(n>1) ans.push_back(n);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
}