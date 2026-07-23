#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        char x='A';
        for(int j=0;j<n-i-1;j++) cout<<" ";
        for(int j=1;j<=2*i+1;j++){
            cout<<x<<" ";
            if(j<=(2*i+1)/2) x++;
            else x--;
        }
        for(int j=0;j<n-i-1;j++) cout<<" ";
        cout<<endl;
    }

    return 0;
}