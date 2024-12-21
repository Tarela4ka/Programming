#include<bits/stdc++.h>

using namespace std;
#define int long long int
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
const int INF = 1000000000;

v<v<v<int>>> vis;
v<v<int>> fd;
v<int> dx{0, 1, 0, -1}, dy{-1, 0, 1, 0};
int n,m; 

struct pos{
    int y, x, z;
};


int canTo(int y, int x, int ty, int tx, int z, int dir){
    dir++;
    int tf = fd[ty][tx];
    if (fd[y][x] == 0){
        if (z == 1){
            if (tf == 1) return 1;
            if (tf == 0){
                if (dir == 4 || dir == 1) return 2;
                else return 3;
            }
        }else if (z == 2){
            if (tf == 1 && (dir == 2 || dir == 3)) return dir;
            if (tf == 0 && (dir == 2 || dir == 3)) return 1;
        }
        else if (z == 3){
            if (tf == 1){
                if (dir == 1) return 2;
                if (dir == 4) return 3;
            }else if (tf == 0 && (dir == 4 || dir == 1)) return 1;
        }
    }else if (fd[y][x] == 1){
        if (z == 1){
            if (tf == 0) return 1;
            else {
                if (dir == 4 || dir == 3) return 3;
                else return 2;
            }
        }else if (z == 2){
            if (tf == 1 && (dir == 4 || dir == 3)) return 1;
            else if (tf == 0){
                if (dir == 4) return 2;
                if (dir == 3) return 3;
            }
        }else if (z == 3){
            if (tf == 0){
                if (dir == 1) return 2;
                if (dir == 2) return 3;
            }else if (tf == 1 && (dir == 2 || dir == 1)) return 1;
        }
    }
    return 0;
}

// int amD = 1;

void dfs(pos sp){
    // cout << amD++ << ": " << endl;
    stack<pos> q; q.push(sp);
    while(!q.empty()){
        pos p = q.top(); q.pop();
        int y = p.y, x = p.x, z = p.z;

        fr(i, 0, 3){
            int ty = y + dy[i], tx = x + dx[i];
            if (ty >= 0 && tx >= 0 && ty < n && tx < m ){
                int tz = canTo(y, x, ty, tx, z, i);
                if (tz && vis[ty][tx][tz] == 0){
                    // cout << ty+1 << " " << tx+1 << " " << tz << " <- ";
                    // cout << y+1 << " " << x+1 << " " << z << " " << endl;
                    q.push({ty, tx, tz});
                    vis[ty][tx][tz] = 1;
                }
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    fd.resize(n, v<int>(m));
    fr(i, 0, n-1){
        fr(j, 0, m-1){
            int c; cin >> c;
            fd[i][j] = c;
        }
    }

    // cout << canTo(1, 0, 2, 0, 1, 2)  << endl;
    vis.resize(n, v<v<int>>(m, v<int>(4, 0)));
    int ans = 0;
    fr(i, 0, n-1)
        fr(j, 0, m-1)
            fr(k, 1, 3)
                if (!vis[i][j][k]){
                    vis[i][j][k] = 1;
                    ans++, dfs({i, j, k});
                }
    cout << ans;
    return 0;
}