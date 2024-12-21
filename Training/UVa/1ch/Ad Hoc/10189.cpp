#include<bits/stdc++.h>

using namespace std;
// #define int long long int
// #define all(a) a.begin(), a.end()

signed main(){
    int t = 1;
    while(true){
        int n,m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        vector<vector<char>> field(n, vector<char>(m));
        vector<vector<int>> ans(n, vector<int>(m, 0));
        int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
        int dy[] = {1, -1, 0, 1, -1, 0, 1, -1};
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> field[i][j];

        for(int y = 0; y < n; y++){
            for(int x = 0; x < m; x++){
                for(int i = 0; i < 8; i++){
                    int ty = y + dy[i];
                    int tx = x + dx[i];
                    if (ty >= 0 && ty < n && tx < m && tx >= 0){
                        if (field[ty][tx] == '*'){
                            ans[y][x]++;
                        }
                    }
                }
            }
        }
        cout << "Field #" << t++ << ":" << endl;
        for(int y = 0; y < n; y++){
            for(int x = 0; x < m; x++){
                if (field[y][x] == '*'){
                    cout << "*";
                } else {
                    cout << ans[y][x];
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
