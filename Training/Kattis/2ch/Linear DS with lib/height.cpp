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
    int p; cin >> p;
    for(int t; t != p;){
        cin >> t;
        int n = 20;
        vi a(n), s(n);
        for(auto& c : a) cin >> c;
        s = a; sort(all(s));
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if (s[i] == a[j]){
                    if (i > j){
                        for(int k = i-1; k >= j; k--)
                            swap(a[i],a[k]);
                    }else if (i < j){
                        for(int k = i+1; k <= j; k++)
                            swap(a[i],a[k]);
                    }
                    ans += abs(i-j);
                    break;
                }
            }
        }
        cout << t << " " << ans << endl;
    }
    return 0;
}