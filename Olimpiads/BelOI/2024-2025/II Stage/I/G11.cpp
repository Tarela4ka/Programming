#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;
#define int long long int
using vi = vector<int>;

const int mod = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vi a(n), b(n);
    for (auto& c : a) {
        cin >> c;
    }for (auto& c : b) {
        cin >> c;
    }
    cout << (n * (n + 1) / 2);
    return 0;
}
