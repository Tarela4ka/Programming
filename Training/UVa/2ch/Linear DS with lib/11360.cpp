#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
// #define int long long int
#define all(a) a.begin(), a.end()
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for(int cas = 1; cas <= t; cas++){
        int n; cin >> n;
        vvi matrix(n, vi(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                char c; cin >> c;
                matrix[i][j] = c-'0';
            }
        }
        int m; cin >> m;
        for(int k = 0; k < m; k++){
            string s; cin >> s;
            if (s == "row" || s == "col"){
                int a,b; cin >> a >> b; a--; b--;
                if (s == "row")
                    for(int i = 0; i < n; i++)
                        swap(matrix[a][i], matrix[b][i]);
                else
                    for(int i = 0; i < n; i++)
                        swap(matrix[i][a], matrix[i][b]);
            } else if (s == "inc" || s == "dec"){
                for(int i = 0; i < n; i++)
                    for(int j = 0; j < n; j++){
                        int x = (matrix[i][j] + (s=="inc" ? 1 : -1))%10;
                        matrix[i][j] = (x < 0 ? 10+x : x);
                    }
            } else if (s == "transpose"){
                // cout << "YES\n";
                for(int i = 0; i < n; i++)
                    for(int j = i; j < n; j++)
                        swap(matrix[i][j], matrix[j][i]);
            }
        }
        cout << "Case #" << cas << endl; 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << matrix[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
}