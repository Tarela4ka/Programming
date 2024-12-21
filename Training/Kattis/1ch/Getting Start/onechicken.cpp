#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int l,r;
    cin >> l >> r;
    cout << "Dr. Chaz ";
    if (r > l) cout << "will have " << r-l << " piece" << (r-l>1 ? "s" : "") << " of chicken left over!";
    if (l > r) cout << "needs " << l-r << " more piece" << (l-r>1 ? "s" : "") << " of chicken!";
    return 0;

}