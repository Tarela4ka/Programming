#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int l,r;
    cin >> l >> r;
    if (l == r && l != 0) cout << "Even " << l+r;
    else if (l == r && l == 0) cout << "Not a moose";
    else cout << "Odd " << max(l,r)*2;
    return 0;
}