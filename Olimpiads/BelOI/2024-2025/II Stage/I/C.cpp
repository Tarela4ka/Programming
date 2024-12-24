#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define int long long int

signed main() {
    int n; cin >> n;

    vector<int> a(n), indx, indn;
	for(auto& c : a) cin >> c;

    int mx = *max_element(a.begin(), a.end());
    int mn = *min_element(a.begin(), a.end());

    for(int i = 0; i < n; i++) {
        if (a[i] == mx) indx.push_back(i);
        if (a[i] == mn) indn.push_back(i);
    }

    int res = 0, i1 = 0, i2 = 0;
    for(int i = 0; i < n; i++) {
        if(i > indx[i1]) i1++;
        if(i > indn[i2]) i2++;

        if(i1 >= indx.size() || i2 >= indn.size()) break;
        int v = max(indx[i1], indn[i2]);
        res += n - v;
    }

    cout << res;

    return 0;
}
