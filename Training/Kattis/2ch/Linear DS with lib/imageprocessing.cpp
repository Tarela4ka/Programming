#include<bits/stdc++.h>

using namespace std;
#define int long long int
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
#define all(a) a.begin(), a.end()

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n,m,h,w;
    cin >> n >> m >> h >> w;
    vvi p(n,vi(m)); 
    vvi kernel(h,vi(w));
    vvi ans(n-h+1, vi(m-w+1));
    for(auto& c : p) for(auto& v : c) cin >> v;
    for(auto& c : kernel) for(auto& v : c) cin >> v;

    for(int i = 0; i < n-h+1; i++)
        for(int j = 0; j < m-w+1; j++)
            for(int y = 0; y < h; y++)
                for(int x = 0; x < w; x++)
                    ans[i][j] += kernel[h-y-1][w-x-1] * p[i+y][j+x];

    for(auto c : ans) {
        for(auto v : c) cout << v << " ";
        cout << endl;
    }
    return 0;
}