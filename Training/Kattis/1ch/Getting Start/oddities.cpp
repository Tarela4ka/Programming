#include<iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if (n % 2) cout << n << " is odd\n";
        else cout << n << " is even\n";
    }
}