#include<bits/stdc++.h>

using namespace std;
// #define int long long int
// #define all(a) a.begin(), a.end()

using vi = vector<int>;
using vvi = vector<vi>;

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n; cin >> n; 
    vvi f(3, vi(3, 0));
    vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1}; 
    for(int caseN = 0; caseN < n; caseN++){
        vvi a(3, vi(3));
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++){
                char c;
                cin >> c;
                a[i][j] = c-'0';
            }

        if (a == f){
            cout << -1 << endl;
            continue;
        }
        int ans = -1;
        while(a != f){
            vvi next(3, vi(3, 0));
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    for(int t = 0; t < 4; t++){
                        int ty = i + dy[t]; int tx = j + dx[t];
                        if (ty >= 0 && ty < 3 && tx >= 0 && tx < 3){
                            next[i][j] = next[i][j]+a[ty][tx];
                        }
                    }
                    next[i][j] %= 2;
                }
            }
            a = next;
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}