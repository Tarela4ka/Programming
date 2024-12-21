#include<iostream>
#include<vector>
#include<string>
using namespace std;

#define int long long int
#define fr(i, a, b) for(int i = (a); i <= (b); i++)
#define rf(i, a, b) for(int i = (a); i >= (b); i--)
#define fe(c, a) for(auto& c : a)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
template <typename T>
using v = vector<T>;
using ii = pair<int, int>;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n; cin >> n;
    v<string> field(n);
    fe(c, field) cin >> c;
    v<v<int>> dp(n, v<int>(n, 0));
    fr(i, 0, n-1) {
        dp[i][0] = field[i][0]-'0';
        dp[0][i] = field[0][i]-'0';
    }
    fr(i, 1, n-1){
        fr(j, 1, n-1){
            if (field[i][j] == '1')
                dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
        }
    }
    // fe(c, dp){
    //     fe(v, c){
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }
    int Max = 0;
    fr(i, 0, n-1)
        fr(j, 0, n-1)
            Max = max(dp[i][j], Max);
    cout << Max*Max;
}