#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define fr(i, a, b) for(int i = (a); i <= (b); i++)
#define rf(i, a, b) for(int i = (a); i >= (b); i--)
#define fe(c, a) for(auto& c : a)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
template <typename T>
using v = vector<T>;
using ii = pair<int, int>;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n; 
        v<v<int>> cnt(n+2);
        fr(i, 0, n-1){
            int c; cin >> c;
            cnt[c].push_back(i);
        }
        set<int> s;
        int k = 1, ans = 1;
        while(!cnt[k].empty()) {
            s.insert(*cnt[k].rbegin());
            cnt[k].pop_back();
        }
        int i = -1;
        while(!s.empty()){
            auto it = upper_bound(all(s), i);
            if (it == s.end()){
                it = s.begin();
                ans++;
            }
            i = *it;
            s.erase(it); k++;
            while(!cnt[k].empty()) {
                s.insert(*cnt[k].rbegin());
                cnt[k].pop_back();
            }
        }
        bool f = false;
        fe(c, cnt) 
            f = (f || !c.empty());

        if (f) cout << "-1\n";
        else cout << ans << '\n';
    }
    return 0;
}