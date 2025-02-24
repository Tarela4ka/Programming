#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
#define int long long int
#define lll __int128_t
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)
#define rf(i, a, b) for (int i = (a); i >= (b); --i)
#define fe(x, y) for (auto& x : y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define mk(a,b) make_pair(a,b)
#define lc(S) ((S<<1)+1)
#define rc(S) ((S<<1)+2)
using ii = pair<int, int>;
using ic = pair<int, char>;
template <typename T>
using v = vector<T>;
using vi = v<int>;
using vvi = v<vi>;

const int MOD = 998244353;
const int INF = 1e9+10;

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    #ifdef DEBUG
    clock_t t1,t2;
    t1=clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t; cin >> t;
    while(t--){
        string s; cin >> s; 
        int n = s.length();
        // cout << n << "\n";
        int l = 0, r = n-1;
        while(l < r && s[l] == s[r]){
            l++; r--;
        }
        if (l >= r){
            cout << 0 << "\n"; continue;
        }
        vvi pref(n, vi(26, 0)), suf(n, vi(26, 0));
        suf[r][s[r]-'a']++;
        pref[l][s[l]-'a']++;    
        fr(i, l+1, r){
            pref[i] = pref[i-1];
            pref[i][s[i]-'a']++;
        }
        rf(i, r-1, l){
            suf[i] = suf[i+1];
            suf[i][s[i]-'a']++;
        }
        
        int L = n/2, R = n/2-1;
        while(L>0 && R < n && s[L] == s[R]){
            L--; R++;
        }
        bool f = true;
        fr(i, 0, 25){
            if (pref[L][i] != suf[R][i]){
                f = false;
            }
        }
        if (f){
            cout << L-l+1 << "\n"; continue;
        }
        if (L == n/2) {L--; R++;}
        int ans = INF;
        fr(i, L, r-1){
            bool f = true;
            fr(j, 0, 25){
                if (pref[i][j] < suf[i+1][j]){
                    f = false;
                }
            }
            if (f) {
                // cout << i-l+1 << "\n";
                ans = min(ans, i-l+1);
                break;
            }
        }
        rf(i, R, l+1){
            bool f = true;
            fr(j, 0, 25){
                if (pref[i-1][j] > suf[i][j]){
                    f = false;
                }
            }
            if (f) {
                // cout << r-i+1 << "\n";
                ans = min(ans, r-i+1);
                break;
            }
        }
        cout << ans << "\n";
    }

    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms\n";
    #endif
}