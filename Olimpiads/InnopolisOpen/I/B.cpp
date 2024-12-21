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
const int N = 1e6+3;

v<int> factorize(int n){
    v<int> a;
    for(int i = 2; i*i <= n; i++){
        while(n%i == 0){
            a.push_back(i);
            n/=i;
        }
    }
    if (n != 1) a.push_back(n);
    return a;
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

    v<int> zalupa(N, 1);
    v<bool> vis(N, 0);
    vis[1] = vis[0] = 1;
    fr(i, 2, N-1){
        if (!vis[i]){
            for(int j = i; j < N; j+=i){
                if (j != i)
                    vis[j] = 1;
                zalupa[j] *= i;
            }
        }
    }
    
    int n, k; cin >> n >> k;
    if (n==2){
        int a,b;
        cin >> a >> b;
        map<int, int> fact1, fact2;
        v<int> facta = factorize(a), factb = factorize(b);
        for(auto c : facta) fact1[c]++;
        for(auto c : factb) fact2[c]++;
        for(auto& [key, val] : fact1) val*=b;
        for(auto& [key, val] : fact2) val*=a;

        fr(i, 0, k-1){
            int c; cin >> c;
            map<int,int> p;
            bool flag1 = true, flag2 = true;
            v<int> f = factorize(c);
            for(auto d : f) p[d]++;
            for(auto d : f) if (p[d] > fact1[d]) flag1 = false;
            for(auto d : f) if (p[d] > fact2[d]) flag2 = false;
            if (flag1||flag2) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    else if (n == 3){
        v<int> anal(n); fe(c, anal) cin >> c;
        sort(all(anal));
        int a = anal[0], b = anal[1], c = anal[2];
        if ((b >= 3 && c >= 3) || (c >= 4 && b >= 2)){
            v<map<int, bool>> fcs(n);
            fr(i, 0, n-1){
                v<int> f = factorize(anal[i]);
                fe(x, f) fcs[i][x]=1;
            }
            fr(i, 0, k-1){
                int x; cin >> x;
                bool f = false;
                v<int> factx = factorize(x);
                fr(i, 0, n-1){
                    v<int> factgcd = factorize(gcd(x, anal[i]));
                    int tx = x;
                    fe(d, factgcd)
                        while(tx%d == 0)
                            tx /= d;
                    if (tx == 1) f = true;
                }
                if (f) cout << "Yes\n";
                else cout << "No\n";
            }
        }else{
            v<int> solvs;
            do{
                v<int> anal2;
                anal2.push_back(pow(anal[0], anal[1]));
                anal2.push_back(pow(anal[1], anal[2]));

                solvs.push_back(pow(anal2[0], anal2[1]));
                solvs.push_back(pow(anal2[1], anal2[0]));
            }while(next_permutation(all(anal)));

            fr(i, 0, k-1){
                int x; 
                cin >> x;
                // cout << x << ": "; 
                bool f = false;
                fe(solve, solvs){
                    if (solve % x == 0) {
                        f = true;
                        break;
                    }
                }
                if (f) cout << "Yes\n";
                else cout << "No\n";
            }
        }
    }else if (n >= 4){
        int ok = 0;
        v<int> a(n); fe(c, a) {cin >> c; ok += (c==1);};
        if (ok >= n-1){
            int num = 1;
            fr(i, 0, n-1) if (a[i] != 1) num = a[i];

            fr(i, 0, k-1){
                int x; cin >> x;
                if (num % x == 0) cout << "Yes\n";
                else cout << "No\n";
            }
        }else{
            v<int> count(N, 0);
            fe(c, a) count[c] = 1;
            v<int> ans(N, 0);
            fr(i, 0, k-1){
                int x; cin >> x;
                // int x = i+1;
                int xc = zalupa[x];
                if (ans[x]){
                    cout << "Yes\n";
                    continue;
                }
                for(int i = xc; i < N; i+=xc){
                    ans[x] |= count[i];
                }
                if (ans[x]) cout << "Yes\n";
                else cout << "No\n";
            }
        }
    }

    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms";
    #endif
    return 0;
}