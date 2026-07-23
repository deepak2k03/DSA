#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    char x='A';
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++) cout<<x<<" ";
        x++;
        cout<<endl;
    }

    return 0;
}