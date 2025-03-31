#include<bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops")
 
using namespace std;
#define int long long int
#define lll __int128_t
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)
#define rf(i, a, b) for (int i = (a); i >= (b); --i)
#define fe(tx, ty) for (auto& tx : ty)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define mk(a,b) make_pair(a,b)
#define pb(b) push_back(b)
#define LSOne(S) (S & (-S))
#define lc(S) ((S << 1) + 1)
#define rc(S) ((S << 1) + 2)
using ii = pair<int, int>;
using ic = pair<int, char>;
template <typename T>
using v = vector<T>;
using vi = v<int>;
using vii = v<ii>;
using vvi = v<vi>;
using vc = v<char>;
using vvc = v<vc>;
 
const int MOD = 1e9+7;
const int INF = 1e18;
const int maxn = 1e5+10;
const int loga = 60;

using state = pair<int, array<array<int, 6>, 5>>;

vi q;

int power(int n, int p){
    int res = 1;
    fr(i, 0, p-1) res*=n;
    return res;
}

int solve1(int n, int m, int t, vi a){
    // int n, m, t; cin >> n >> m >> t;
    // q.resize(m); fe(c, q) cin >> c;
    q = a;
    map<state, int> dp;
    queue<pair<state, int>> s;
    vvi powers(5, vi(7));
    fr(i, 0, 4)
        fr(j, 0, 6) powers[i][j] = power(i+1, j+1);
    {
        state p; p.first = 0;
        fr(i, 0, 4)fr(j, 0, 5)p.second[i][j] = 0;
        s.push(mk(p, 0));
    }
    v<pair<int, pair<int, int>>> prior;
    fr(i, 0, 4)
        fr(j, 0, 5) prior.push_back(mk(powers[i][j+1]-2*powers[i][j], mk(i, j)));
    sort(rall(prior));
    // fe(v, prior){
    //     cout << v.first << " " << v.second.first+1 << " " << v.second.second+1 << '\n';
    // }

    while(!s.empty()){
        auto [st, step] = s.front(); s.pop();
        auto [k, c] = st; 
        int sum = 0, ans = 0;
        fr(i, 0, 4)
        fr(j, 0, 5){
            ans += powers[i][j]*c[i][j];
            sum += c[i][j];
        }
        if (dp[st] >= ans && step != 0) continue;
        else dp[st] = ans;
        if (step >= t) continue;
        fr(i, 0, 4){
            fr(j, 0, 5){
                if (c[i][j] >= 2){
                    c[i][j] -= 2; c[i][j+1]++;
                    s.push(mk(mk(k, c), step+1));
                    c[i][j] += 2; c[i][j+1]--;
                }
            }
        }
        // fe(v, prior){
        //     auto [r, ind] = v;
        //     auto [i, j] = ind;
        //     if (c[i][j] >= 2){
        //         c[i][j] -= 2; c[i][j+1]++;
        //         s.push(mk(mk(k, c), step+1));
        //         c[i][j] += 2; c[i][j+1]--;
        //         break;
        //     }
        // }
        if (sum < n && k < m){
            c[q[k]-1][0]++;
            s.push(mk(mk(k+1, c), step+1));
            c[q[k]-1][0]--;
        }
    }
    int result = 0;
    fe(c, dp) result = max(c.second, result);
    // cout << result;
    return result;
}

int solve2(int n, int m, int t, vi a){
    // int n, m, t; cin >> n >> m >> t;
    // q.resize(m); fe(c, q) cin >> c;
    q = a;
    map<state, int> dp;
    queue<pair<state, int>> s;
    vvi powers(5, vi(7));
    fr(i, 0, 4)
        fr(j, 0, 6) powers[i][j] = power(i+1, j+1);
    {
        state p; p.first = 0;
        fr(i, 0, 4)fr(j, 0, 5)p.second[i][j] = 0;
        s.push(mk(p, 0));
    }
    v<pair<int, pair<int, int>>> prior;
    fr(i, 0, 4)
        fr(j, 0, 5) prior.push_back(mk(powers[i][j+1]-2*powers[i][j], mk(i, j)));
    sort(rall(prior));
    // fe(v, prior){
    //     cout << v.first << " " << v.second.first+1 << " " << v.second.second+1 << '\n';
    // }

    while(!s.empty()){
        auto [st, step] = s.front(); s.pop();
        auto [k, c] = st; 
        int sum = 0, ans = 0;
        fr(i, 0, 4)
        fr(j, 0, 5){
            ans += powers[i][j]*c[i][j];
            sum += c[i][j];
        }
        if (dp[st] >= ans && step != 0) continue;
        else dp[st] = ans;
        if (step >= t) continue;
        // fr(i, 0, 4){
        //     fr(j, 0, 5){
        //         if (c[i][j] >= 2){
        //             c[i][j] -= 2; c[i][j+1]++;
        //             s.push(mk(mk(k, c), step+1));
        //             c[i][j] += 2; c[i][j+1]--;
        //         }
        //     }
        // }
        fe(v, prior){
            auto [r, ind] = v;
            auto [i, j] = ind;
            if (c[i][j] >= 2){
                c[i][j] -= 2; c[i][j+1]++;
                s.push(mk(mk(k, c), step+1));
                c[i][j] += 2; c[i][j+1]--;
                break;
            }
        }
        if (sum < n && k < m){
            c[q[k]-1][0]++;
            s.push(mk(mk(k+1, c), step+1));
            c[q[k]-1][0]--;
        }
    }
    int result = 0;
    fe(c, dp) result = max(c.second, result);
    // cout << result;
    return result;
}

void solve(){
    int n, m, t; cin >> n >> m >> t;
    q.resize(m); fe(c, q) cin >> c;
    map<state, int> dp;
    queue<pair<state, int>> s;
    vvi powers(5, vi(6));
    fr(i, 0, 4)
        fr(j, 0, 5) powers[i][j] = power(i+1, j+1);
    {
        state p; p.first = 0;
        fr(i, 0, 4)fr(j, 0, 5) p.second[i][j] = 0;
        s.push(mk(p, 0));
    }
    v<pair<int, pair<pair<int, int>, pair<int, int>>>> prior;
    fr(i, 0, 4){
        fr(j, 0, 4){
            fr(k, 1, 4){
                if (k+j <= 5)
                    prior.push_back(mk(powers[i][j+k]-powers[1][k-1]*powers[i][j], mk(mk(i, j), mk(powers[1][k-1], k))));
            }
        }
    }
    // fr(i, 0, 4)
    //     fr(j, 0, 5) prior.push_back(mk(powers[i][j+1]-2*powers[i][j], mk(i, j)));
    sort(rall(prior));
    // fe(v, prior){
    //     cout << v.first << " " << v.second.first.first+1 << " " << v.second.first.second+1 << " " << v.second.second << '\n';
    // }

    while(!s.empty()){
        auto [st, step] = s.front(); s.pop();
        auto [k, c] = st; 
        int sum = 0, ans = 0;
        fr(i, 0, 4)
        fr(j, 0, 5){
            ans += powers[i][j]*c[i][j];
            sum += c[i][j];
        }
        if (dp[st] >= ans && step != 0) continue;
        else dp[st] = ans;
        if (step >= t) continue;
        
        // fr(i, 0, 4){
        //     fr(j, 0, 5){
        //         if (c[i][j] >= 2){
        //             c[i][j] -= 2; c[i][j+1]++;
        //             s.push(mk(mk(k, c), step+1));
        //             c[i][j] += 2; c[i][j+1]--;
        //         }
        //     }
        // }
        // if (step == k && step == 9){
        //     cout << ans << '\n';
        //     fe(v, c){
        //         fe(z, v) cout << z << " ";
        //         cout << '\n';
        //     }
        // }
        fe(v, prior){
            auto [r, temp] = v;
            auto [ind, temp2] = temp;
            auto [i, j] = ind;
            auto [am, twost] = temp2;
            // if (step == k && step == 9){
            //     if (c[i][j] >= am) {
            //         cout << r << " " << i << " " << j << " " << c[i][j] << " " << am << '\n';
            //         cout << (step + am -1 <= t) << '\n';
            //     }
            // }
            if (c[i][j] >= am && step+am-1 <= t){
                c[i][j] -= am; c[i][j+twost]++;
                s.push(mk(mk(k, c), step+am-1));
                c[i][j] += am; c[i][j+twost]--;
                break;
            }
        }
        if (sum < n && k < m){
            c[q[k]-1][0]++;
            s.push(mk(mk(k+1, c), step+1));
            c[q[k]-1][0]--;
        }
    }
    int result = 0;
    state z;
    fe(c, dp) {
        if (c.second > result){
            z = c.first;
            result = max(c.second, result);
        }
    }
    // cout << z.first << '\n';
    // fr(i, 0, 4){
    //     fr(j, 0, 5){
    //         cout << z.second[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    cout << result;
}
 
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    #ifdef DEBUG
    srand(time(NULL));
    clock_t t1,t2;
    t1=clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    // int t; cin >> t;
    // int t = 1;
    // fr(n, 1, 20){
    //     fr(m, 1, 20){
    //         fr(t, 1, 20){
    //             vi a(m);
    //             fr(i, 0, m-1) a[i] = (rand()*147) % 5 + 1;
    //             if (solve1(n, m, t, a) != solve2(n, m, t, a) ){
    //                 cout << n << ' ' << m << " " << t << endl;
    //                 fe(c, a) cout << c << ' ';
    //                 cout << endl;
    //             }
    //         }
    //     }
    // }
    // while(t--) 
    // int n, m, t;
    // cin >> n >> m >> t;
    // vi a(m); fe(c, a) cin >> c;
    solve();

    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms\n";
    #endif
    return 0;
}
// ⠀⢸⠂⠀⠀⠀⠘⣧⠀⠀⣟⠛⠲⢤⡀⠀⠀⣰⠏⠀⠀⠀⠀⠀⢹⡀
// ⠀⡿⠀⠀⠀⠀⠀⠈⢷⡀⢻⡀⠀⠀⠙⢦⣰⠏⠀⠀⠀⠀⠀⠀⢸⠀
// ⠀⡇⠀⠀⠀⠀⠀⠀⢀⣻⠞⠛⠀⠀⠀⠀⠻⠀⠀⠀⠀⠀⠀⠀⢸⠀
// ⠀⡇⠀⠀⠀⠀⠀⠀⠛⠓⠒⠓⠓⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀
// ⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠀
// ⠀⢿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⠀⠀⢀⡟⠀
// ⠀⠘⣇⠀⠘⣿⠋⢹⠛⣿⡇⠀⠀⠀⠀⣿⣿⡇⠀⢳⠉⠀⣠⡾⠁⠀
// ⣦⣤⣽⣆⢀⡇⠀⢸⡇⣾⡇⠀⠀⠀⠀⣿⣿⡷⠀⢸⡇⠐⠛⠛⣿⠀
// ⠹⣦⠀⠀⠸⡇⠀⠸⣿⡿⠁⢀⡀⠀⠀⠿⠿⠃⠀⢸⠇⠀⢀⡾⠁⠀
// ⠀⠈⡿⢠⢶⣡⡄⠀⠀⠀⠀⠉⠁⠀⠀⠀⠀⠀⣴⣧⠆⠀⢻⡄⠀⠀
// ⠀⢸⠃⠀⠘⠉⠀⠀⠀⠠⣄⡴⠲⠶⠴⠃⠀⠀⠀⠉⡀⠀⠀⢻⡄⠀
// ⠀⠘⠒⠒⠻⢦⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⠞⠛⠒⠛⠋⠁⠀
// ⠀⠀⠀⠀⠀⠀⠸⣟⠓⠒⠂⠀⠀⠀⠀⠀⠈⢷⡀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠙⣦⠀⠀⠀⠀⠀⠀⠀⠀⠈⢷⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⣼⣃⡀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣆⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠉⣹⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡆ Made by @Tarela4ka