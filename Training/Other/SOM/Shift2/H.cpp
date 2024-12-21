#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
#include<stack>

using namespace std;
// #define int long long int
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define mk(a,b) make_pair(a,b)
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
using ii = pair<int, int>;

int n, m, v, k;
const int INF = 1e9;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m >> v >> k;

    vector<int> cont(k);
    vector<vector<int>> Sdist(n, vector<int>(m, INF));
    queue<int> q;
    for (int i = 0; i < v; i++) {
        int a, b; cin >> a >> b; a--; b--;
        q.push(a*m+b);
        Sdist[a][b] = 0;
    }
    for (auto& c : cont) cin >> c;

    vi dx = { 1, -1, 0, 0 }, dy = { 0, 0, -1, 1 };
    while (!q.empty()) {
        auto y = q.front()/m, x = q.front()%m;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ty = y + dy[i], tx = x + dx[i];
            if (ty >= 0 && tx >= 0 && tx < m && ty < n && Sdist[ty][tx] > Sdist[y][x] + 1) {
                Sdist[ty][tx] = Sdist[y][x] + 1;
                q.push(ty*m+tx);
            }
        }
    }
    set<pair<int, pair<short, short>>> s;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (Sdist[i][j] != 0)
                s.insert(mk( Sdist[i][j], mk(i, j)));

    int minD = 0;
    sort(rall(cont));
    for (auto c : cont) {
        auto [d, cords] = *s.begin(); 
        s.erase(s.begin());
        minD += d*c;
    }

    cout << minD << endl;
    return 0;
}