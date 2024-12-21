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
const int INF = 1000000000;

int n,k; 
int memo[180][80][2] = {};
v<int> a;
v<int> pr;

int P(int L, int s, int maxK, int p){
    // cout << endl << L << " " << s << " " << maxK << " " << p;
    if (L == n) return s;
    if (memo[L][maxK][p]) {
        int bk = memo[L][maxK][p];
        // cout << " YES " << bk;
        return P(L+bk, s+(pr[L+bk] - pr[L])*p, bk, !p);
    }
    int bestK = 0;
    int bestR = INF*(!p);
    fr(i, 1, maxK){
        if (L+i > n)
            break;
        int r = P(L+i, s + (pr[L+i]-pr[L])*p, i, !p);
        if ((p && r > bestR) || (!p && r < bestR)){
            bestK = i;
            bestR = r;
        }
    }
    fr(i, bestK, maxK) 
        memo[L][i][p] = bestK;
    return bestR;
}

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    #ifdef DEBUG
    clock_t t1,t2;
    t1=clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    cin >> n; a.resize(n);
    fe(c, a) cin >> c;
    cin >> k;
    pr.resize(n+1);
    pr[0] = 0;
    fr(i, 0, n-1) pr[i+1] = pr[i] + a[i];
    cout << P(0, 0, k, 1);

    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms";
    #endif
    return 0;
}