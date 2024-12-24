#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;
using ll = long long;

int main(){
    ll n, s;
    cin >> n;
    vector<int> digits;
    for(; n != 0; n/=10)
        digits.push_back(n%10);
    s = digits.size();
    if (s % 2 == 1) cout << digits[s/2];
    else cout << digits[s/2-1] + digits[s/2];
    return 0;
}