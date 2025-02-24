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
#define pb(a) push_back(a)
#define lc(S) ((S<<1)+1)
#define rc(S) ((S<<1)+2)
using ii = pair<int, int>;
using ic = pair<int, char>;
template <typename T>
using v = vector<T>;
using vi = v<int>;
using vii = v<ii>;
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
        int n;
        int s1, s2; cin >> n >> s1 >> s2; s1--; s2--;
        v<v<vii>> G(n, v<vii>(n));
        vi verts;
        {
            vvi g1, g2;
            g1.resize(n); g2.resize(n);
            vii temp1; 
            int m1; cin >> m1;
            fr(i, 0, m1-1){
                int a, b; cin >> a >> b; a--; b--;
                if (a < b) swap(a,b);
                temp1.pb(mk(a,b));
                g1[a].pb(b); g1[b].pb(a);
            }   
            sort(all(temp1));
            int m2; cin >> m2;
            fr(i, 0, m2-1){
                int a, b; cin >> a >> b; a--; b--;
                if (a < b) swap(a,b);
                if (binary_search(all(temp1), mk(a, b))) {
                    verts.pb(a); verts.pb(b);
                }
                g2[a].pb(b); g2[b].pb(a);
            }   
            fr(v1, 0, n-1){
                fr(v2, 0, n-1){
                    fe(e1, g1[v1]){
                        fe(e2, g2[v2]){
                            G[v1][v2].pb(mk(e1, e2));
                        }
                    }
                }
            }

        }
        vvi dp(n, vi(n, INF));
        priority_queue<pair<int, ii>> q;
        q.push(mk(0, mk(s1, s2)));
        while(!q.empty()){
            auto [cost, st] = q.top(); q.pop();
            auto [v1, v2] = st; cost=-cost;
            if (cost != dp[v1][v2]) continue;
            
            dp[v1][v2] = cost;
            for(auto [tov1, tov2] : G[v1][v2]){
                int c = cost + abs(tov1 - tov2);
                if (dp[tov1][tov2] > c){
                    q.push(mk(-c, mk(tov1, tov2)));
                }
            }
        }
        int ans = INF;
        fe(v, verts){
            ans = min(ans, dp[v][v]);
        }
        cout << (ans == INF ? -1 : ans) << "\n";
    }

    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms\n";
    #endif
}