#include<bits/stdc++.h>

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

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s; cin >> s;
    int maxL = 0, l = 0;
    for(int i = 0; i < s.length(); i++){
        if (s[i] == '0') l++;
        else {
            maxL = max(l, maxL);
            l = 0;
        }
    }
    cout << max(l, maxL);
    return 0;
}