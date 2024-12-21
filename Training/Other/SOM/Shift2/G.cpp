#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<stack>

using namespace std;
#define int long long int
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define mk(a,b) make_pair(a,b)
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
using ii = pair<int, int>;

int n, k;

int fact(int z){
    int ans = 1;
    for(int i = 1; i <= z; i++){
        ans*=i;
    }
    return ans;
}

int permToNum(vi a){
    int perm = 1;
    set<int> s;
    for(int i = 1; i <= n; i++) s.insert(i);

    for(int i = 1; i <= n; i++){
        int x = 0;
        for(auto c : s){
            if (c == a[i-1]) break;
            x++;
        }
        s.erase(a[i-1]);
        perm += fact(n-i) * x;
    }
    return perm;
}

void numToPerm(int p){
    if (p > fact(n)) {
        cout << -1; return;
    }
    set<int> s;
    for(int i = 1; i <= n; i++) s.insert(i);
    vi perm;
    for(int i = 1; i < n; i++){
        int x = ceil((double)p/fact(n-i));
        int j;
        for(auto c : s){
            x--;
            j = c;
            if (x == 0) break;
        }
        s.erase(j);
        p = p % fact(n-i);
        perm.push_back(j);  
    }
    perm.push_back(*s.begin());
    for(auto c : perm) cout << c << " ";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> k;
    vector<int> a(n);
    for(auto& c : a) cin >> c;
    int perm = permToNum(a);
    // cout << perm << endl;
    numToPerm(perm+k);
    return 0;
}