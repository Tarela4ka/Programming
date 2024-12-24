#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>

using namespace std;
using ll = long long;

int main(){
    ll maxE = -1e9-5, minE = 1e9+5;
    for(int i = 0; i < 5; i++){
        ll c;
        cin >> c;
        maxE = max(maxE, c);
        minE = min(minE, c);
    }
    cout << (maxE - minE);

    return 0;
}