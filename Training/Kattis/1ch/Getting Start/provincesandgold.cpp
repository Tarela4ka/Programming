#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int a,b,c,bp;
    cin >> a >> b >> c;
    bp = a*3 + b * 2 + c;
    bool f = false;
    if (bp >= 2){
        f = true;
        if (bp >= 8)cout << "Province";
        else if (bp >= 5) cout << "Duchy";
        else cout << "Estate";
    }
    if (f) cout << " or ";
    if (bp >= 6) cout << "Gold";
    else if (bp >=3) cout << "Silver";
    else cout << "Copper";
    return 0;
}