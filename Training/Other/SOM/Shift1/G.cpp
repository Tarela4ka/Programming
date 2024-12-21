#include<bits/stdc++.h>

using namespace std;

int n,m;

int main(){
    cin >> n >> m;
    vector<vector<char>> field(n,vector<char>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> field[i][j];
    
    vector<vector<int>> vis(n, vector<int>(m, 1));
    map<char, pair<int, int>> r;
    r['U'] = {-1, 0}, r['D'] = {1, 0}, r['L'] = {0, -1}, r['R'] = {0, 1}; 
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++){
        if (field[i][0] == 'L'){
            q.push({i, 0});
            vis[i][0] = 0;
        }
        if (field[i][m-1] == 'R'){
            q.push({i, m-1});
            vis[i][m-1] = 0;
        }
    }
    for(int i = 0; i < m; i++){
        if (field[0][i] == 'U'){
            q.push({0, i});
            vis[0][i] = 0;
        }
        if (field[n-1][i] == 'D'){
            q.push({n-1, i});
            vis[n-1][i] = 0;
        }
    }

    vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
    while(!q.empty()){
        auto [y, x] = q.front(); q.pop();
        for(int i = 0; i < dx.size(); i++){
            int ty = y + dy[i], tx = x + dx[i];
            if (ty >= 0 && tx >= 0 && ty < n && tx < m && vis[ty][tx]){
                if (dy[i] + r[field[ty][tx]].first == 0 && r[field[ty][tx]].second + dx[i] == 0){
                    vis[ty][tx] = 0;
                    q.push({ty, tx});
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            ans+=vis[i][j];

    cout << ans;
    return 0;
}