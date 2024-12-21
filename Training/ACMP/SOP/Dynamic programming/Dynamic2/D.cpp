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
v<int> a;
int mas[100][100];

int step(int l, int r, int s, int dir){
    if (mas[l][r] == 1) 
        return step(l+1, r, s+a[l]*(!dir), !dir);
    else if (mas[l][r] == 2)
        return step(l, r-1, s+a[r]*(!dir), !dir);

    if (l == r) {
        if (!dir) return s + a[l];
        else return s;
    }

    if (!dir){
        int s1 = step(l+1, r, s+a[l], !dir);
        int s2 = step(l, r-1, s+a[r], !dir);
        if (s1 > s2) mas[l][r] = 1;
        else mas[l][r] = 2;
        return max(s1, s2);
    }else{
        int s1 = step(l+1, r, s, !dir);
        int s2 = step(l, r-1, s, !dir);
        if (s1 < s2) mas[l][r] = 1;
        else mas[l][r] = 2;
        return min(s1, s2);
    }   
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
    
    int n; cin >> n;
    int sum = 0;
    a.resize(n); fe(c, a){
        cin >> c;
        sum += c;
    }

    int p1 = step(0, n-1, 0, 0); 
    int p2 = sum - p1;
    // cout << p1 << " " << p2 << endl;
    if (p1 > p2) cout << 1;
    else if (p1 < p2) cout << 2;
    else cout << 0;

    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms";
    #endif
    return 0;
}