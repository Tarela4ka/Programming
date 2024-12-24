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

int p,q;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> p >> q;
    int x = ceil(q/p);
    if (x == q/p){
        cout << x+1;
    } else{
        cout << x;
    }
    return 0;
}
