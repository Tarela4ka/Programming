#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;
#define int long long int
using vi = vector<int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vi dp(n, 1e10+50);
    dp[0] = 0;
    vi a(n), b(n);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i + j >= n) break;
            if (a[i] > a[i + j]) continue;
            if (dp[i + j] > dp[i] + floor((double) a[i + j] / a[i]) + b[i + j]) {
                dp[i + j] = dp[i] + floor((double) a[i + j] / a[i]) + b[i + j];
            }
        }
    }
    cout << (dp[n - 1] == 1e10+50 ? -1 : dp[n-1]);
    //cout << dp[n - 1];
    return 0;
}
