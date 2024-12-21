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

int getPbyN(int n, int p){
    int ans = 0;
    int a = p;
    while(p <= n){
        ans += floor(n/p); 
        p *= a;
    }
    return ans;
}

int getMinN(int p, int c){
    int res = p;
    while(getPbyN(res, p) < c){
        res+=p;
    }
    return res;
}


signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n,m,k; 
    cin >> n >> m >> k;
    v<v<int>> dp(n, v<int>(m, 0));
    v<v<int>> a(n, v<int>(m));
    fe(c, a) fe(v, c) cin >> v;
    dp[0][0] = a[0][0];
    fr(i, 1, m-1) dp[0][i] = dp[0][i-1] + a[0][i];

    fr(i, 1, n-1) dp[i][0] = dp[i-1][0] + a[i][0];

    fr(i, 1, n-1)
        fr(j, 1, m-1)
            dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+a[i][j];

    int res = 0;
    fr(i, 0, k-1){
        int x1,y1,x2,y2;
        cin >> y1 >> x1 >> y2 >> x2;
        y1--;x1--;x2--;y2--;
        int add = dp[y2][x2];
        if (y1 == 0 && x1 != 0){
            add -= dp[y2][x1-1];
        }else if(x1 == 0 && y1 != 0){
            add -= dp[y1-1][x2];
        }else if(x1 != 0 && y1 != 0){
            add -= dp[y2][x1-1];
            add -= dp[y1-1][x2];
            add += dp[y1-1][x1-1];
        }
        res+=add;
    }
    cout << res;
    return 0;
}