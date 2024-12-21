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
using vii = vector<ii>;

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string s1,s2;
    getline(cin, s1); getline(cin, s2);
    int x1 = 0, x2 = 0;
    for(auto c : s1) {
        if (c == '+') x1++; 
        else if (c == '-') x1--;
    }
    int p = 0;
    for(auto c : s2) {
        if (c == '+') x2++; 
        else if (c == '-') x2--;
        else if (c == '?') p++;
    }
    int all = 1 << p, suc = 0; 
    for(int i = 0; i < 1<<p; i++){
        int bitmask = i;
        int x3 = x2;
        for(int j = 0; j < p; j++){
            if(bitmask & 1) x3++;
            else x3--;
            bitmask = bitmask >> 1;
        }
        if (x3 == x1) suc++;
    }
    printf("%.9f", (double)suc/all);
    return 0;
}