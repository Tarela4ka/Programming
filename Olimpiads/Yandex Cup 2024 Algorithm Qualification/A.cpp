#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;

ll lcm(ll x, ll y) {
    return (x / gcd(x, y)) * y;
}

ll count(ll x, ll a, ll b, ll c) {
    return (x/lcm(a, b) + x/lcm(a, c) + x/lcm(b, c) - 3*(x/lcm(lcm(a,b), c)));
}

ll solve(ll a, ll b, ll c, ll n) {
    ll left = 1;
    ll right = 1e18;
    
    while (left < right) {
        ll mid = left + (right - left) / 2;
        if (count(mid, a, b, c) < n) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    if (count(left, a, b, c) == n) {
        return left;
    } else {
        return -1;
    }
}

int main() {
    ll a, b, c, n;
    cin >> a >> b >> c >> n;
    cout << ll(solve(a, b, c, n)) << endl;

    return 0;
}