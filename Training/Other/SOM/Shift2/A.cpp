#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n,m;
    cin >> n >> m;
    cout << gcd(n,m) << " " << n*m/gcd(n,m);
    return 0;
}