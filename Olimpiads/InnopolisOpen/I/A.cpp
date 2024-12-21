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
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int a,b,k;
    cin >> a >> b >> k;
    if (k >= b){
        cout << 0;
        return 0;
    }
    int minS = 1e16;
    for(int x = 1; x <= k; x++){
        int r = b-(x*a%b);
        int l = b-r;
        int S;
        if(l%r == 0 && (b/r)<=x && (b-r == r)){
            int z = x%(b/r);
            S = a*r*z;
        }else{
            S = x*a*r;
        }
        minS = min(S, minS);
    }
    cout << minS;
    return 0;
}