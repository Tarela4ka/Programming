#include <bits/stdc++.h>

using namespace std;

int p, n,m, k;

using vi = vector<int>;
using vvi = vector<vi>;

vi dy = {1, -1, 0, 0}, dx = {0, 0, 1, -1};

vvi battle(vvi field, int gen){
    if (gen == k) return field;
    vvi next = field;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int c = 0; c < dy.size(); c++){
                int ty = i + dy[c], tx = j + dx[c];
                if (ty >= 0 && ty < n && tx >= 0 && tx < m && field[ty][tx] == (field[i][j]+1)%p){
                    // cout << ty << " " << tx << " " << i << " " << j << endl;
                    next[ty][tx] = field[i][j];
                }
            }
        }
    }
    return battle(next, gen+1);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(true){
        cin >> p >> n >> m >> k;
        if (p == 0 && n == 0) break;
        vvi start(n, vi(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> start[i][j];
            }
        }
        vvi finish(n, vi(m));
        finish = battle(start, 0);
        for(int i = 0; i < n; i++){
            cout << finish[i][0];
            for(int j = 1; j < m; j++){
                cout << ' ' << finish[i][j];
            }
            cout << endl;
        }
    }
}