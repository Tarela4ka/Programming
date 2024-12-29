#include<bits/stdc++.h>

using namespace std;
#define int long long int
#define lll __int128_t
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)
#define rf(i, a, b) for (int i = (a); i >= (b); --i)
#define fe(x, y) for (auto& x : y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define mk(a,b) make_pair(a,b)
using ii = pair<int, int>;
using ic = pair<int, char>;
template <typename T>
using vec = vector<T>;

const int MOD = 1000000007;
const int INF = 1000000000;

int power(int b, int n){
    int r = 1;
    fr(i, 0, n-1) r*=b;
    return r;
}

struct edge{
    int ver;
    int time;
    int temp;
};

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
        int n, m; cin >> n >> m;
        int mxdt = INF;
        vec<vec<edge>> graph(n);
        fr(i, 0, m-1){
            int a,b,t1,t2;
            cin >> a >> b >> t1 >> t2;
            a--; b--;
            graph[a].push_back({b, t1, t2});
            mxdt = min(t2, mxdt);
        }
        if (mxdt == 0){
            vec<int> dist(n, INF); dist[0] = 0;
            set<ii> q;
            fr(i, 0, n-1) 
                q.insert(mk(dist[i], i));
            while(!q.empty()){
                auto [time, ver] = *q.begin(); 
                q.erase(q.begin());
                fe(c, graph[ver]){
                    if (dist[c.ver] > time+c.time){
                        q.erase(mk(dist[c.ver], c.ver));
                        dist[c.ver] = time+c.time;
                        q.insert(mk(dist[c.ver], c.ver));
                    }
                }
            }
            cout << ((dist[n-1]==INF) ? (-1) : (dist[n-1])) << endl;
        }else if (mxdt > 0){
            vec<int> dist(n, INF); dist[0] = 0;
            vec<int> tv(n, 0); tv[0] = 0;
            set<pair<int, ii>> q;
            fr(i, 0, n-1) 
                q.insert(mk(dist[i], mk(tv[i], i)));
            while(!q.empty()){
                auto [time, p] = *q.begin(); 
                auto [temp, ver] = p;
                q.erase(q.begin());
                fe(c, graph[ver]){
                    // cout << ver << " " << c.ver << " " << ver << " " << c.ver << " " << endl;
                    if (dist[c.ver] > time+c.time && c.temp+temp <= 30 || c.temp+temp != tv[c.ver]){
                        q.erase(mk(dist[c.ver], mk(tv[c.ver], c.ver)));
                        dist[c.ver] = time+c.time;
                        tv[c.ver] = c.temp+temp;
                        q.insert(mk(dist[c.ver], mk(tv[c.ver], c.ver)));
                    }
                }
            }
            cout << ((dist[n-1]==INF) ? (-1) : (dist[n-1])) << endl;
        }
    }

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