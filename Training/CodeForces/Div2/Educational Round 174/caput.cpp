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
using vii = v<ii>;
using vvi = v<vi>;

const int INF = 1e18+10;

vi dy = {1, -1, 0, 0}, dx = {0, 0, 1, -1};

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
        int n, m; cin >> n >> m;
        vi colors(n*m+1, INF);
        vvi a(n, vi(m)); fe(c, a)fe(v, c) {
            cin >> v;
            colors[v] = 0;
        }
        vvi adj(n, vi(m, 0));
        fr(i, 0, n-1){
            fr(j, 0, m-1){
                int c = 0;
                fr(k, 0, 3){
                    int y = i + dy[k], x = j + dx[k];
                    if (y >= 0 && y < n && x >= 0 && x < m){
                        if (a[i][j] == a[y][x])
                            c++;
                    }
                }
                adj[i][j] = c;
            }
        }
        int ans = 0;
        vvi vis(n, vi(m, 0));
        rf(k, 4, 1){
            fr(i, 0, n-1){
                fr(j, 0, m-1){
                    if (adj[i][j] == k && !vis[i][j]){
                        ans++; vis[i][j] = 1;
                        colors[a[i][j]]++;
                        fr(c, 0, 3){
                            int y = i + dy[c], x = j + dx[c];
                            if (y >= 0 && y < n && x >= 0 && x < m){
                                if (a[i][j] == a[y][x])
                                    adj[y][x]--;
                            }
                        }
                    }
                }
            }
        }
        // fe(c, colors) cout << c << "\n";
        int z = 0;
        fe(c, colors){
            if (c != INF) {
                ans++;
                z = max(z, c+1);
            }
        }
        cout << ans-z << "\n";
    }

    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms\n";
    #endif
}