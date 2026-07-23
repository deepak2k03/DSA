#include <iostream>
using namespace std;

int main() {
    int m,n;
    cin >>m>>n;
    for(int i=0;i<n;i++){
        cout<<"*";
    }
    cout<<endl;
    for(int i=0;i<m-2;i++){
        cout<<"*";
        for(int j=0;j<n-2;j++) cout<<" ";
        cout<<"*";
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        cout<<"*";
    }
    cout<<endl;
    return 0;
}