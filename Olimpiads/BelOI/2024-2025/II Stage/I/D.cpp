#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;
#define int long long int
using vi = vector<int>;
using vs = vector<string>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vs a(n);
    for (auto& c : a) {
        cin >> c;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (a[i][k] != a[j][k]) ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
