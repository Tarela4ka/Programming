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

const int INF = 1e18+10;

int msb(int x){
    int j = 0;
    for(; x; j++) x >>= 1;
    return j-1;
}

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
        int n, q; cin >> n >> q;
        vi a(n); fe(c, a) cin >> c;
        reverse(all(a));
        vvi bits(31, vi(n+2));
        vi pref(n+1); pref[0] = 0;
        fr(i, 1, n) pref[i] = (pref[i-1]^a[i-1]);
        fr(j, 0, 30){
            bits[j][n] = bits[j][n+1] = n+1;
            rf(i, n-1, 0){
                if(msb(a[i]) == j) bits[j][i] = i+1;
                else bits[j][i] = bits[j][i+1];
            }
        }
        while(q--){
            int x; cin >> x;
            int prevxor = 0, pos = 0, maxpos = n+1, lsb = msb(x);
            rf(i, 30, lsb+1) maxpos = min(maxpos, bits[i][0]);
            int prb;
            while(x){
                prb = lsb;
                lsb = msb(x);
                int newpos = bits[lsb][pos];
                rf(i, prb, lsb+1)
                    maxpos = min(maxpos, bits[i][pos]);
                pos = newpos-1;
                if (newpos >= maxpos) break;
                x = (x^pref[pos]^prevxor);
                prevxor = pref[pos];
                if (x >= a[pos]){
                    x ^= a[pos];
                    prevxor ^= a[pos];
                    pos++;
                }else{
                    break;
                }
            }
            cout << min(maxpos-1, pos) << " ";
        }
        cout << "\n";
    }

    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms\n";
    #endif
}