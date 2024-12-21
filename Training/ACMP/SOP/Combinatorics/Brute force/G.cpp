#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<ctime>
#include<map>
 
using namespace std;
 
#define int long long int
#define lll __int128
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
int n, k;
 
bool hit(int y1, int x1, int y2, int x2){
    if (y1 == y2 || x1 == x2) return 1;
    if (abs(x1-x2) == abs(y1-y2)) return 1;
    if ((abs(x1-x2)==2 && abs(y1-y2)==1) || (abs(x1-x2)==1 && abs(y1-y2)==2)) return 1;
    return false;
}
 
int P(v<int> mags, int m, int sx, int sy){
    if (m == 0) return 1;
     
    v<int> stx(n, 0);
    fe(c, mags) 
        if (c!=-1)
            stx[c] = 1;
 
    int res = 0;
    fr(y, sy, n-1){
        if (m > n-y) return res;
        fr(x, sx, n-1){
            bool f = 1;
            fr(i, 0, n-1) 
                if (mags[i] != -1) 
                    if (hit(y, x, i, mags[i]))
                        f = 0;
            if (f) {
                mags[y] = x;
                res+=P(mags, m-1, x, y);
                mags[y] = -1;
            }
        }
        sx = 0;
    }
    return res;
}
 
int factorial(int n){
    int res = 1;
    fr(i, 1, n) res*=i;
    return res;
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
 
    cin >> n >> k;
    v<int> mags(n, -1);
    cout << P(mags, k, 0, 0);
 
    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms";
    #endif
    return 0;
}