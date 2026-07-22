# include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int f=1;
    int temp=1;
    for(int i=0;i<n;i++){
        temp=f;
        for(int j=0;j<i+1;j++){
            cout<<temp<<" ";
            temp=!temp;
        }
        f=!f;
        cout<<endl;
    }
}