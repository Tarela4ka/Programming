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
using v = vector<T>;
using vi = v<int>;
using vii = v<ii>;
using vvi = v<vi>;
using vc = v<char>;
using vvc = v<vc>;

const int MOD = 1e9+7;
const int INF = 1e16;

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

    int n; cin >> n;
    string s; cin >> s;
    
    int alfa, beta, gamma;
    alfa=beta=gamma=0;
    fe(c, s)
        if (c == 'a') alfa++;
        else if (c=='b') beta++;
        else gamma++;
    int nec = alfa%2 + beta%2 + gamma%2 - n%2;    
    if (nec != 0) {
        cout << -1;
        return 0;
    }
    
    vvi p(3, vi(3, 0));
    fr(i, 0, n/2-1){
        p[s[i]-'a'][s[n-1-i]-'a']++;
    }
    int ans = 0;
    if (n%2 == 1){
        int need;
        if (alfa%2) need = 0;
        if (beta%2) need = 1;
        if (gamma%2) need = 2;
        int st = s[n/2]-'a';
        if (st != need){
            if (p[st][need] > 0){
                p[need][need]++; p[st][need]--;
                ans++;
            }else if (p[need][st] > 0){
                p[need][need]++; p[need][st]--;
                ans++;
            }else{
                fr(i, 0, 2){
                    if (i != need){
                        if (p[need][i] > 0){
                            p[st][i]++; p[need][i]--;
                            ans++;
                        }else if (p[i][need] > 0){
                            p[i][st]++; p[i][need]--;
                            ans++;
                        }
                    }
                }
            }
        }
    }
    fr(i, 0, 2){
        fr(j, 0, 2){
            if (i != j) {
                ans += p[i][j]/2;
                p[i][j] = p[i][j]%2;
            }
        }
    }
    fr(i, 0, 2){
        int fl = i, sl = i;
        fr(j, 0, 2) if (i!=j && p[i][j] > 0) fl = j;
        fr(j, 0, 2) if (i!=j && p[j][i] > 0) sl = j;
        if (sl == i && fl != i) {
            fr(j, 0, 2) if (i!=j && p[j][i] > 0 && j != fl) sl = j;
            if (sl != i) {
                p[i][i]++; p[fl][sl]++;
                p[i][fl]--; p[i][sl]--;
                ans++;
            }
        }else{
            if (fl != i && sl != i) {
                p[i][i]++; p[fl][sl]++;
                p[i][fl]--; p[sl][i]--;
                ans++;
            }
        }
    }
    cout << ans;

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