#include<bits/stdc++.h>

using namespace std;
// #define int long long int
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)
#define rf(i, a, b) for (int i = (a); i >= (b); --i)
#define fe(x, y) for (auto& x : y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define mk(a,b) make_pair(a,b)
using ii = pair<int, int>;
template <typename T>
using v = vector<T>;

const int MOD = 1000000007;
const int INF = 1000000007;

v<int> dy{1,-1,0,0}, dx{0,0,1,-1};
v<v<int>> field, d;
int n, m; 
ii s, f;

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    #ifdef DEBUG
    clock_t t1,t2;
    t1=clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    {
        auto&[s1,s2] = s;
        auto&[f1,f2] = f;
        cin >> n >> m >> s1 >> s2 >> f1 >> f2;
        s1--; s2--; f1--; f2--;
    }
    field.resize(n, v<int>(m));
    d.resize(n, v<int>(m, INF));
    d[s.first][s.second] = 0;
    fr(i, 0, n-1) 
        fr(j,0,m-1) {
            // int c; cin >> c;
            // field[i][j] = (c&1);
            cin >> field[i][j];
        }
    queue<ii> q;
    q.push(s);
    while(!q.empty()){
        auto [y, x] = q.front();
        q.pop();
        fr(i,0,3){
            int ty = dy[i] + y;
            int tx = dx[i] + x;
            if (ty >= 0 && ty < n && tx >= 0 && tx < m && d[ty][tx] > d[y][x]+field[ty][tx]) {
                d[ty][tx] = d[y][x]+field[ty][tx];
                q.push(mk(ty, tx));
            }
        }
    }
    cout << d[f.first][f.second];

    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms";
    #endif
    return 0;
}