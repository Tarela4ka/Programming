#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin >> n >> m;
    vector<vector<char>> field(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> field[i][j];
        }
    }
    int ans = 1;
    for(int i = 0; i < m; i++){
        bool f = true;
        for(int j = 0; j < n; j++) if (field[j][i] != '_') f = false; 
        ans+=f;
    }
    cout << ans;
}