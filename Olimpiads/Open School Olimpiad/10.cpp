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

int ans = 0;
const string ROOT = "";

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int ans = 0, i = 0, c = 0;
    string s; cin >> s;
    int n = s.length();
    v<char> m(n, ' ');
    while( i < n ){
        if (s[i] == ']'){
            if (c > 0 && c <= n && m[c-1]=='['){
                m[c-1] = ' ';
                c--;
            }else{
                ans++;
            }
        }else{
            m[c] = '[';
            c++;
        }
        i++;
    }
    ans = (ans+1)/2;
    cout << ans;
    return 0;
}