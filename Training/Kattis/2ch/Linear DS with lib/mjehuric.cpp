#include<bits/stdc++.h>

using namespace std;
#define int long long int
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
#define all(a) a.begin(), a.end()

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n = 5;
    vi a(n), s;
    for(auto& c : a) cin >> c;
    s=a; sort(all(s));
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n; j++){
            if (a[j] < a[j-1]) {
                swap(a[j], a[j-1]);
                for(auto c : a) cout << c << " ";
                cout << endl;
            }
        }
    }
    return 0;
}