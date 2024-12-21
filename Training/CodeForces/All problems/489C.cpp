#include<bits/stdc++.h>

using namespace std;
// #define int long long int
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
    int l, s; cin >> l >> s;
    if ((s==0 && l!=1) || s > l*9){
        cout << "-1 -1";
        return 0;
    }
    int ts = s;
    string ans = "";
    for(int i = 1; i <= l; i++){
        if (i == 1){
            if ((l-i)*9 > ts){
                ans += '1';
                ts--;
            }else{
                ans += ((ts-(l-i)*9)+'0');
                ts -= ts-(l-i)*9;
            }
        }else{
            if ((l-i)*9 >= ts){
                ans += '0';
            }else{
                ans += ((ts-(l-i)*9)+'0');
                ts -= ts-(l-i)*9;
            }
        }
    }
    cout << ans << " ";
    ts = s;
    ans = "";
    for(int i = 1; i <= l; i++){
        if (ts >= 9){
            ans += '9';
            ts -= 9;
        }else{
            ans += (ts+'0');
            ts -= ts;
        }
    }
    cout << ans;
    
    return 0;
}