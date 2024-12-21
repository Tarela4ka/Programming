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

string cyclichui(string s){
    string res = s;
    fr(i, 1, s.length()-1){
        res[i] = s[i-1];
    }
    res[0] = s[s.length()-1];
    return res;
}

int ttod(string s){
    int res = 0;
    reverse(all(s));
    fr(p, 0, s.length()-1){
        res += (1 << p)*(s[p]-'0');
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n; cin >> n;
    string s = "";
    do{
        s += (n&1)+'0';
        n >>= 1;
    }while(n);

    reverse(all(s));
    int maxN = ttod(s);
    fr(i, 0, s.length()-1){
        s = cyclichui(s);
        maxN = max(maxN, ttod(s));
    }
    cout << maxN; 
    return 0;
}