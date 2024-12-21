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
const int INF = 1e9;

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    #ifdef DEBUG
    clock_t t1,t2;
    t1=clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n; cin >> n;
    v<int> a(n); cin >> a[0];
    int k,b,m; 
    cin >> k >> b >> m;
    fr(i, 1, n-1) 
        a[i] = (k*a[i-1] + b) % m;
    

    v<int> dp(n+2, INF);
    v<int> di(n+2, INF);
    v<int> pr(n+2, INF);
    map<int, int> p;
    int Max = 0;
    // fe(c, a) cout << c << " ";
    // cout << endl;

    dp[0] = -1;
    di[0] = -1;
    fr(i, 0, n-1){
        int ind = (lower_bound(dp.begin()+1, dp.end(), a[i]) - dp.begin());
        dp[ind] = a[i];
        di[ind] = i;
        pr[i] = di[ind-1];
        Max = max(Max, ind);
    }
    // fe(c, dp) cout << c << " ";
    // cout << endl;
    // fe(c, di) cout << c << " ";
    // cout << endl;
    // fe(c, pr) cout << c << " ";
    // cout << endl;

    v<int> path;
    int c = di[Max];
    while(true){
        path.push_back(a[c]);
        c = pr[c];
        if (c == -1) break;
    }
    reverse(all(path));
    fe(c, path) cout << c << " ";


    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms";
    #endif
    return 0;
}