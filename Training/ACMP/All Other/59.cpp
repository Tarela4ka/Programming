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
 
const int MOD = 1e9;
 
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k = 0;
    cin >> n >> k;
    string s = "";
    while(n){
        s += n%k+'0';
        n/=k;
    }
    int p = 1, sum = 0;
    fe(c, s){
        p *= (c - '0');
        sum += (c-'0');
    }
    cout << p-sum << endl;
    return 0;
}