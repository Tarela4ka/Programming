#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;
#define int long long int
using vi = vector<int>;

signed main() {
	int h, m, s;
	cin >> h >> m >> s;
	int res = h * 3600 + m * 60 + s;
	cout << (86400 - res);
    return 0;
}
