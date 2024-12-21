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

int fact(int a){
    int s = sqrt(a); int ans = 0;
    for(int i = 2; i <=s; i++){
        while(a%i==0){
            a/=i;
            ans++;
        }
    }
    if (a != 1) ans++;
    return ans;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a,b; cin >> a >> b;
    cout << fact(a)+fact(b)-2*fact(gcd(a,b));
    return 0;
}