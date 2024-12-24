#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<set>
#include<map>

using namespace std;
#define int long long int
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using ii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, p, c, x, ind = 0;
    cin >> n;
    cin >> x;
    p = x;
    bool f1 = true, f2 = false;
    for(int i = 1; i < n; i++){
        cin >> c;
        if (c < p){
            if (f2) f1 = false;
            f2 = true;
            ind = i;
        }
        if (f2) if (c > x) f1 = false;
        p = c;
    }
    if (f1){
        if (ind == 0) ind = n;
        cout << "Shift " << n - ind;
    }else{
        cout << "Impossible";
    }
    return 0;
}
