#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
#define int long long int
#define lll __int128_t
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)
#define rf(i, a, b) for (int i = (a); i >= (b); --i)
#define fe(x, y) for (auto& x : y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define mk(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define lc(S) ((S<<1)+1)
#define rc(S) ((S<<1)+2)
using ii = pair<int, int>;
using ic = pair<int, char>;
template <typename T>
using v = vector<T>;
using vi = v<int>;
using vii = v<ii>;
using vvi = v<vi>;

const int MOD = 998244353;
const int INF = 1e9+10;


signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    #ifdef DEBUG
    clock_t t1,t2;
    t1=clock();
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vi vis(n+1, 0);
        vi a(n); fe(c, a) {
            cin >> c;
            vis[c] = 1;
        }
        int no = 0; fr(i, 1, n) if (!vis[i]) {no = i; break;}
        int ans1, ans2;
        int i = 0, j = 0; 
        fr(x, 1, n-1) if (a[x] > a[i]) i=x;
        fr(x, 1, n-1) if (a[x] < a[j]) j=x;
        int r = a[i]-a[j];
        i++; j++;
        if (no){
            fr(x, 1, n)
                if (x != no){
                    cout << "? " << no << " " << x << endl;
                    break;
                }
            cin >> ans1;
            if (ans1 == 0){
                cout << "! A" << endl;
            }else{
                cout << "! B" << endl;
            }
        }else{
            cout << "? " << i << " " << j << endl;
            cin >> ans1;
            cout << "? " << j << " " << i << endl;
            cin >> ans2; 
            if (ans1 != ans2){
                cout << "! A" << endl;
            }else{
                if ((ans1 >= n-1 || ans2 >= n-1)){
                    cout << "! B" << endl;
                }else{
                    cout << "! A" << endl;
                }
            }
        }
    }

    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms\n";
    #endif
}