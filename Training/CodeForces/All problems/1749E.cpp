#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops") 
 
using namespace std;
#define int long long int
#define lll __int128_t
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)
#define rf(i, a, b) for (int i = (a); i >= (b); --i)
#define fe(tx, ty) for (auto& tx : ty)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define mk(a,b) make_pair(a,b)
#define pb(b) push_back(b)
#define LSOne(S) (S & (-S))
#define lc(S) ((S << 1))
#define rc(S) ((S << 1) + 1)
// #define par(S) ((S << 1) + 2)
using ii = pair<int, int>;
using ic = pair<int, char>;
template <typename T>
using v = vector<T>;
using vi = v<int>;
using vii = v<ii>;
using vvii = v<vii>;
using vvi = v<vi>;
using vc = v<char>;
using vvc = v<vc>;
 
const int MOD = 1e9+7;
const int INF = 1e9;
const int maxn = 1e5+10;


vi tx{-1, 1, 0, 0}, ty{0, 0, -1, 1};
vi dix{1, 1, -1, -1}, diy{1, -1, 1, -1};

void solve(){
    int n, m; cin >> n >> m;
    vvc field(n, vc(m)); vvi dist(n, vi(m, INF)); 
    fe(c, field) fe(v, c) cin >> v;
    fr(i, 0, n-1){
        fr(j, 0, m-1){
            if (field[i][j] == '#'){
                fr(k, 0, 3){
                    if (i + ty[k] >= 0 && i + ty[k] < n && j + tx[k] >= 0 && j + tx[k] < m){
                        dist[i+ty[k]][j+tx[k]] = -1;
                    }
                }
            }
        }
    }
    vvii ret(n, vii(m, mk(0, 0)));
    {
        queue<ii> q;
        fr(i, 0, n-1){
            if (dist[i][0] == -1) continue;
            dist[i][0] = (field[i][0] != '#');
            q.push({i, 0});
        } 
        
        while(!q.empty()){
            auto [y, x] = q.front(); q.pop();
            fr(k, 0, 3){
                int dx = x + dix[k], dy = y + diy[k];
                if (dy >= 0 && dy < n && dx >= 0 && dx < m && dist[dy][dx] > dist[y][x] + (field[dy][dx] != '#')){
                    q.push({dy, dx});
                    dist[dy][dx] = dist[y][x] + (field[dy][dx] != '#');
                    ret[dy][dx] = {y, x};
                }
            }
        }
    }
    ii best = {INF, -1};
    fr(i, 0, n-1){
        if (dist[i][m-1] != -1 && best.first > dist[i][m-1] ){
            best.first = dist[i][m-1];
            best.second = i;
        }
    }
    if (best.first == INF){
        cout << "NO\n";
        return;
    }else{
        cout << "YES\n";
    }
    int y = best.second, x = m-1;
    while(x != 0){
        field[y][x] = '#';
        auto [dy, dx] = ret[y][x];
        y = dy; x = dx;
    }
    field[y][x] = '#';
    fe(c, field) {fe(v, c) cout << v; cout << '\n';}
}

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    srand(time(NULL));
    #ifdef DEBUG
    clock_t t1,t2;
    t1=clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t; cin >> t;
    while(t--) 
        solve();

    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms";
    #endif
    return 0;
}