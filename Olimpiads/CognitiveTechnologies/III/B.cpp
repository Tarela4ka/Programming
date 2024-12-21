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
const int INF = 1000000007;

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    #ifdef DEBUG
    clock_t t1,t2;
    t1=clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map<int, map<char, bool>> r;
        v<int> tasks(10000, 0);
        v<string> res(n);
        fe(c, res) {
            cin >> c;
            int com = c.find(",");
            int num = stoi(c.substr(com-4,4));
            if (c[com+3] == 'O'){
                r[num][c[com+1]] = 1;
            } else {
                r[num][c[com+1]];
            }
        }
        int ans = 0;
        int maxRes = 0;
        fe(c, r){
            int res = 0;
            fe(v, c.second) if (v.second == 1) res++;
            tasks[c.first] = res;
            maxRes = max(res, maxRes);
        }
        fe(c, r)
            if (tasks[c.first] == maxRes) 
                ans++;
        cout << ans << endl;
    }
    

    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms";
    #endif
    return 0;
}